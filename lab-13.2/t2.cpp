#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    ofstream file("fellows2.txt", ios::out);
    string rollNo, fullName;
    double cgpa;
    char choice;

    do {
        cout << "Enter roll number: ";
        getline(cin, rollNo);
        rollNo.resize(15, ' ');

        cout << "Enter full name: ";
        getline(cin, fullName);
        fullName.resize(25, ' ');
        cout << "Enter CGPA: ";
        cin >> cgpa;
        cin.ignore();

        file << rollNo << fullName << fixed << setprecision(2) << setw(5) << cgpa << endl;

        cout << "Do you want to enter more data (y/n)? ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    file.close();
    return 0;
}
