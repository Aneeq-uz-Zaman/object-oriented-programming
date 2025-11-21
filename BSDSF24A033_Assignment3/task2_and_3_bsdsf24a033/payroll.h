#ifndef PAYROLL_H
#define PAYROLL_H

#include "employee.h"

class Payroll
{
private:
    static const int MAX_EMPLOYEES = 100;
    Employee *employees[MAX_EMPLOYEES];
    int count=0;

public:
    Payroll();
    ~Payroll();
    Payroll(const Payroll &other);
    Payroll &operator=(const Payroll &other);
    Payroll(Payroll &&other) noexcept;
    Payroll &operator=(Payroll &&other) noexcept;

    void loadEmployees();
    void printSalaries() const;
    void addEmployee(Employee *e);
};

#endif
