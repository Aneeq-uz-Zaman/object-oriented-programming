#include "payroll.h"
#include "officer.h"
#include "dailywager.h"
#include <iostream>

Payroll::Payroll()
{
    for (int i = 0; i < 10; i++)
        employees[i] = nullptr;
}

Payroll::~Payroll()
{
    for (int i = 0; i < 10; i++)
        delete employees[i];
}

Payroll::Payroll(const Payroll &other)
{
    for (int i = 0; i < 10; i++)
    {
        if (other.employees[i])
        {
            if (auto o = dynamic_cast<Officer *>(other.employees[i]))
                employees[i] = new Officer(*o);
            else if (auto d = dynamic_cast<DailyWager *>(other.employees[i]))
                employees[i] = new DailyWager(*d);
            else
                employees[i] = nullptr;
        }
        else
        {
            employees[i] = nullptr;
        }
    }
}

Payroll &Payroll::operator=(const Payroll &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 10; i++)
            delete employees[i];
        for (int i = 0; i < 10; i++)
        {
            if (other.employees[i])
            {
                if (auto o = dynamic_cast<Officer *>(other.employees[i]))
                    employees[i] = new Officer(*o);
                else if (auto d = dynamic_cast<DailyWager *>(other.employees[i]))
                    employees[i] = new DailyWager(*d);
                else
                    employees[i] = nullptr;
            }
            else
            {
                employees[i] = nullptr;
            }
        }
    }
    return *this;
}

Payroll::Payroll(Payroll &&other) noexcept
{
    for (int i = 0; i < 10; i++)
    {
        employees[i] = other.employees[i];
        other.employees[i] = nullptr;
    }
}

Payroll &Payroll::operator=(Payroll &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 10; i++)
            delete employees[i];
        for (int i = 0; i < 10; i++)
        {
            employees[i] = other.employees[i];
            other.employees[i] = nullptr;
        }
    }
    return *this;
}

void Payroll::loadEmployees()
{
    employees[0] = new Officer("Sami", "DS", 1, 5000);
    employees[1] = new DailyWager("Shah", "HR", 2, 200, 2);
}

void Payroll::printSalaries() const
{
    for (int i = 0; i < 10; i++)
    {
        if (employees[i])
            std::cout << employees[i]->getName() << ": $" << employees[i]->take_home_income() << std::endl;
    }
}
void Payroll::addEmployee(Employee *e)
{
    if (count < MAX_EMPLOYEES)
    {
        employees[count++] = e;
    }
}
