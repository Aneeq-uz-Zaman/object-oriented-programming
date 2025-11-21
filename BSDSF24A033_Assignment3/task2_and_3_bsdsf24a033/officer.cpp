#include "officer.h"
#include <cmath>

Officer::Officer(string n, string d, int s, int ms) : Employee(n, d, s), monthly_salary(ms) {}

int Officer::getMonthlySalary() const
{
    return monthly_salary;
}

float Officer::take_home_income() const
{
    return round(monthly_salary * 0.9f);
}
