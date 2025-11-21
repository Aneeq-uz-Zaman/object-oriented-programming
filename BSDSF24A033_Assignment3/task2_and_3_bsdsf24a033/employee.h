#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    string department;
    int scale;

public:
    Employee(string, string, int);
    virtual ~Employee() = default;
    string getName() const;
    string getDepartment() const;
    int getScale() const;
    virtual float take_home_income() const;
};

#endif
