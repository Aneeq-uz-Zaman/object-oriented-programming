#include "dailywager.h"

DailyWager::DailyWager(string n, string d, int s, int dw, int ac) : Employee(n, d, s), daily_wage(dw), absent_count(ac) {}

int DailyWager::getDailyWage() const
{
    return daily_wage;
}

int DailyWager::getAbsentCount() const
{
    return absent_count;
}

float DailyWager::take_home_income() const
{
    return (30 - absent_count) * daily_wage;
}
