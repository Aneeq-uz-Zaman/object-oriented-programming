#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

class Board {
    char arr[9];
    bool setMove(int index, char mark) {
        if (arr[index - 1] >= '1' && arr[index - 1] <= '9') {
            arr[index - 1] = mark;
            return true;
        }
        return false;
    }
    friend class Game;
public:
    void init() {
        for (int i = 0; i < 9; i++) arr[i] = i + '1';
    }
    void getBoard(char b[]) {
        for (int i = 0; i < 9; i++) b[i] = arr[i];
    }
    void draw() {
        cout << "\n ___ ___ ___ \n";
        cout << "|   |   |   |\n";
        cout << "| " << arr[0] << " | " << arr[1] << " | " << arr[2] << " |\n";
        cout << "|___|___|___|\n";
        cout << "|   |   |   |\n";
        cout << "| " << arr[3] << " | " << arr[4] << " | " << arr[5] << " |\n";
        cout << "|___|___|___|\n";
        cout << "|   |   |   |\n";
        cout << "| " << arr[6] << " | " << arr[7] << " | " << arr[8] << " |\n";
        cout << "|___|___|___|\n";
    }
};

class Player {
protected:
    char mark;
public: 
    Player(char m) : mark(m) {}
    virtual int getMove() = 0;
    char getMark() const { return mark; }
};

class HPlayer : public Player {
public:
    HPlayer(char mark) : Player(mark) {}
    int getMove() {
        int index;
        cout << "Enter box number to put " << getMark() << " : ";
        cin >> index;
        return index;
    }
};

class NonsenseComputerPlayer : public Player {
public:
    NonsenseComputerPlayer(char m) : Player(m) { srand(time(0)); }
    int getMove() {
        int index = rand() % 9 + 1;
        cout << "Nonsense Computer chose cell: " << index << endl;
        return index;
    }
};

class SensibleComputerPlayer : public Player {
    Board* board;
public:
    SensibleComputerPlayer(char m, Board* b) : Player(m), board(b) { srand(time(0)); }
    int getMove() {
        char b[9];
        board->getBoard(b);
        char opponent = (mark == 'X') ? 'O' : 'X';

        for (int i = 0; i < 9; i++) {
            if (b[i] >= '1' && b[i] <= '9') {
                char backup = b[i];
                b[i] = mark;
                if (checkWin(b, i, mark)) return i + 1;
                b[i] = backup;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (b[i] >= '1' && b[i] <= '9') {
                char backup = b[i];
                b[i] = opponent;
                if (checkWin(b, i, opponent)) return i + 1;
                b[i] = backup;
            }
        }
        // Any free cell
        for (int i = 0; i < 9; i++) {
            if (b[i] >= '1' && b[i] <= '9') return i + 1;
        }
        return 1;
    }
    bool checkWin(char b[], int pos, char mark) {
        int row = pos / 3;
        if (b[row * 3] == mark && b[row * 3 + 1] == mark && b[row * 3 + 2] == mark) return true;
        int col = pos % 3;
        if (b[col] == mark && b[col + 3] == mark && b[col + 6] == mark) return true;
        if (b[0] == mark && b[4] == mark && b[8] == mark) return true;
        if (b[2] == mark && b[4] == mark && b[6] == mark) return true;
        return false;
    }
};

class Game {
    Board b;
    Player *p1, *p2;
public:
    Game(int mode, char m1, char m2) {
        init();
        switch (mode) {
            case 1: p1 = new HPlayer(m1); p2 = new HPlayer(m2); break;
            case 2: p1 = new HPlayer(m1); p2 = new NonsenseComputerPlayer(m2); break;
            case 3: p1 = new HPlayer(m1); p2 = new SensibleComputerPlayer(m2, &b); break;
            case 4: p1 = new NonsenseComputerPlayer(m1); p2 = new SensibleComputerPlayer(m2, &b); break;
        }
        toss();
        b.draw();
    }
    void toss() {
        if (dynamic_cast<HPlayer*>(p1) && dynamic_cast<HPlayer*>(p2)) return;
        cout << "\nTossing to decide who starts...\n";
        srand(time(0));
        if (rand() % 2 == 1) {
            cout << "Player 2 won the toss and will start first!\n";
            swap(p1, p2);
        } else {
            cout << "Player 1 won the toss and will start first!\n";
        }
    }
    void init() { b.init(); }
    bool checkRow(char b[], int r, char mark) {
        for (int i = r; i < r + 3; i++) if (b[i] != mark) return false;
        return true;
    }
    bool checkColumn(char b[], int r, char mark) {
        for (int i = r; i < 9; i += 3) if (b[i] != mark) return false;
        return true;
    }
    bool checkD1(char b[], char mark) {
        return (b[0] == mark && b[4] == mark && b[8] == mark);
    }
    bool checkD2(char b[], char mark) {
        return (b[2] == mark && b[4] == mark && b[6] == mark);
    }
    bool checkWin(char b[], int pos, char mark) {
        if (checkRow(b, (pos / 3) * 3, mark)) return true;
        if (checkColumn(b, pos % 3, mark)) return true;
        if ((pos == 0 || pos == 4 || pos == 8) && checkD1(b, mark)) return true;
        if ((pos == 2 || pos == 4 || pos == 6) && checkD2(b, mark)) return true;
        return false;
    }
    void runGame() {
        int count = 0, pos;
        char a[9], mark;
        Player *currentPlayer = p1;
        while (count < 9) {
            do {
                pos = currentPlayer->getMove();
                mark = currentPlayer->getMark();
            } while (!b.setMove(pos, mark));

            b.draw();
            b.getBoard(a);
            if (checkWin(a, pos - 1, mark)) break;

            currentPlayer = (currentPlayer == p1) ? p2 : p1;
            count++;
        }
        if (count == 9) cout << "It's a Draw!\n";
        else cout << "Player with mark '" << mark << "' won!\n";
    }
};

int main() {
    int mode;
    char p1mark, p2mark;
    do {
        cout << "\nSelect Game Mode:\n";
        cout << "1. Human vs Human\n";
        cout << "2. Human vs Nonsense Computer\n";
        cout << "3. Human vs Sensible Computer\n";
        cout << "4. Nonsense vs Sensible Computer\n";
        cout << "Enter your choice: ";
        cin >> mode;
        cout << "Enter mark for Player 1: "; cin >> p1mark;
        cout << "Enter mark for Player 2: "; cin >> p2mark;

        Game g(mode, p1mark, p2mark);
        g.runGame();

        cout << "\nDo you want to play again? (y/n): ";
        char again; cin >> again;
        if (again != 'y' && again != 'Y') break;
    } while (true);

    return 0;
}
