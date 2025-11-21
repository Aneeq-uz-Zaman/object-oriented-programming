#ifndef OFFICER_H
#define OFFICER_H

#include "employee.h"

class Officer : public Employee
{
private:
    int monthly_salary;

public:
    Officer(string, string, int, int);
    int getMonthlySalary() const;
    float take_home_income() const override;
};

#endif
