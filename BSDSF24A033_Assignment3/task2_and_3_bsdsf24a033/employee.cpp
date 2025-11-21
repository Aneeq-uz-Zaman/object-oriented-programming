#include "employee.h"

Employee::Employee(string n, string d, int s) : name(n), department(d), scale(s) {}

string Employee::getName() const
{
    return name;
}

string Employee::getDepartment() const
{
    return department;
}

int Employee::getScale() const
{
    return scale;
}

float Employee::take_home_income() const
{
    throw 0;
    return 0;
}
