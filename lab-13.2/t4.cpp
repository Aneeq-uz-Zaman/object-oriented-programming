#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream fin("fellows2.txt");
    vector<string> lines;
    string line;

    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    ofstream copy("fellows3.txt");
    for (string l : lines) {
        copy << l << endl;
    }
    copy.close();

    const int RECORD_SIZE = 47;

    fstream file("fellows2.txt", ios::in | ios::out);
    if (!file) {
        cout << "File could not be opened.\n";
        return 1;
    }

    file.seekp(-2 * RECORD_SIZE, ios::end);

    string newRecord = "BsCDF99H999    Bara Admi                 4.00\n";
    file<< newRecord; 

    file.close();
    cout << "Second last record updated.\n";

    return 0;
}
