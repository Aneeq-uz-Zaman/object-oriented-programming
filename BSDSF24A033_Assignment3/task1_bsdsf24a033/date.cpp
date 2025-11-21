#include <iostream>
#include "Date.h"

using namespace std;

Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void Date::display()
{
    cout << day << "/" << month << "/" << year << endl;
}
