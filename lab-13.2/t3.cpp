#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("fellows2.txt", ios::in);
    if (!file) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    int recordNumber;
    cout << "Enter record number: ";
    cin >> recordNumber;

    const int RECORD_SIZE = 46;
    file.seekg((recordNumber - 1) * RECORD_SIZE, ios::beg);

    char roll[16], name[26], cgpa[6];
    file.read(roll, 15); 
    file.read(name, 25); 
    file.read(cgpa, 5);  


    cout << "Fellow Number: " << recordNumber << "\n";
    cout << "Roll Number: " << roll << "\n";
    cout << "Name: " << name << "\n";
    cout << "CGPA: " << cgpa << "\n";

    file.close();
    return 0;
}
