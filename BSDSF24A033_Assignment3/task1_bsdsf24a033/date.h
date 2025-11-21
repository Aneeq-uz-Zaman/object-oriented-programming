#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date();
    Date(int, int, int);
    void display();
};

#endif
