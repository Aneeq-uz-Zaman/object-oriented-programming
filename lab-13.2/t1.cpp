#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file;
    file.open("fellows1.txt", ios::app);

    string rollNo, fullName;
    double cgpa;
    char choice;

    do {
        cout << "Enter roll number (e.g., BSEF19M5XX): ";
        getline(cin, rollNo);

        cout << "Enter full name: ";
        getline(cin, fullName);

        cout << "Enter CGPA: ";
        cin >> cgpa;


        file << rollNo << ", " << fullName << ", " << cgpa << endl;

        cout << "Do you want to enter more data (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    file.close();
    return 0;
}
