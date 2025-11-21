#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    char name[30];

    void input() {
        cout << "Enter roll no: ";
        cin >> rollNo;
        cin.ignore(); // clear input buffer
        cout << "Enter name: ";
        cin.getline(name, 30);
    }

    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

void writeToFile() {
    ofstream fout("student.dat", ios::binary | ios::app);
    if (!fout) {
        cout << "Error opening file for writing.\n";
        return;
    }

    Student s;
    s.input();
    fout.write((char*)&s, sizeof(s));
    fout.close();

    cout << "Record saved successfully.\n";
}

void readFromFile() {
    ifstream fin("student.dat", ios::binary);
    if (!fin) {
        cout << "Error opening file for reading.\n";
        return;
    }

    Student s;
    cout << "\nAll Records:\n";
    while (fin.read((char*)&s, sizeof(s))) {
        s.display();
    }
    fin.close();
}

void updateRecord() {
    fstream file("student.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Error opening file for updating.\n";
        return;
    }

    Student s;
    int roll;
    bool found = false;

    cout << "Enter roll no to update: ";
    cin >> roll;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.rollNo == roll) {
            cout << "\nExisting Record: ";
            s.display();

            cout << "\nEnter new data:\n";
            s.input();

            int pos = -1 * sizeof(s);
            file.seekp(pos, ios::cur);
            file.write((char*)&s, sizeof(s));
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Record updated successfully.\n";
    else
        cout << "Record not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n=== Student Record System ===\n";
        cout << "1. Write Record\n";
        cout << "2. Read All Records\n";
        cout << "3. Update Record\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: writeToFile(); break;
            case 2: readFromFile(); break;
            case 3: updateRecord(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
