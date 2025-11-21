#ifndef DAILYWAGER_H
#define DAILYWAGER_H

#include "employee.h"

class DailyWager : public Employee
{
private:
    int daily_wage;
    int absent_count;

public:
    DailyWager(string, string, int, int, int);
    int getDailyWage() const;
    int getAbsentCount() const;
    float take_home_income() const override;
};

#endif
