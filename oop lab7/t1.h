#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string name;
    int rollNo;
    float cgpa;

public:
    Student();
    Student(string n, int r, float c);
    void set(string n, int r, float c);
    void displayDetails();
    bool isOnDeansList();
};
