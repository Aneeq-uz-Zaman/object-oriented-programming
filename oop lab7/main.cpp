#include <iostream>
#include "t1.h"
#include <string>
using namespace std;

int main()
{

    Student students[3];

    for (int i = 0; i < 3; i++)
    {
        string name;
        int rollNo;
        float cgpa;

        cout << "Enter details for student " << (i + 1) << ":" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Roll No: ";
        cin >> rollNo;
        cout << "CGPA: ";
        cin >> cgpa;

        students[i].set(name, rollNo, cgpa);
    }

    cout << endl
         << endl
         << "Student Details:"
         << endl;
    for (int i = 0; i < 3; i++)
    {
        students[i].displayDetails();
        if (students[i].isOnDeansList())
            cout << "Status: On Dean's Honor List" << endl;
        else
            cout << "Status: Not on Dean's Honor List" << endl;
    }

    return 0;
}