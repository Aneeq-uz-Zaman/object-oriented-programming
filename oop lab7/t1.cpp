// Task 1: Student Records Management System (50 marks)
// Create a class Student with the following:

// Private data members: name, rollNo, cgpa

// Constructor, setDetails(), displayDetails()

// Member function to check if the student is on Dean’s Honor List (cgpa >= 3.5)

// Write a main.cpp to:

// Input details of 3 students.

// Display their details and indicate if they're on Dean's list.
#include <iostream>
#include "t1.h"
#include <string>
using namespace std;

Student::Student(string n, int r, float c) : name(n), rollNo(r), cgpa(c) {}

Student::Student()
{
    name = "";
    rollNo = 0;
    cgpa = 0.0;
}

void Student::set(string n, int r, float c)
{
    name = n;
    rollNo = r;
    cgpa = c;
}
void Student::displayDetails()
{
    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "CGPA: " << cgpa << endl;
}
bool Student::isOnDeansList()
{
    return cgpa >= 3.5;
}
