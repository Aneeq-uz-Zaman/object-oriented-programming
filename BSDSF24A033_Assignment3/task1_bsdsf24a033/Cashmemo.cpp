#include <iostream>
#include "Cashmemo.h"

using namespace std;

Cashmemo::Cashmemo()
{
    memoId = 0;
    count = 0;
}

Cashmemo::Cashmemo(int id, Date d)
{
    memoId = id;
    date = d;
    count = 0;
}

void Cashmemo::addItem(Saleline s)
{
    if (count < 10)
    {
        items[count++] = s;
    }
}

void Cashmemo::display()
{
    cout << "Memo ID: " << memoId << endl;
    cout << "Date: ";
    date.display();
    for (int i = 0; i < count; i++)
    {
        items[i].display();
    }
}
