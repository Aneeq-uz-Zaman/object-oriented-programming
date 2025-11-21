#ifndef CASHMEMO_H
#define CASHMEMO_H

#include "Date.h"
#include "Saleline.h"

using namespace std;

class Cashmemo
{
private:
    int memoId;
    Date date;          // Aggregation
    Saleline items[10]; // Composition
    int count;

public:
    Cashmemo();
    Cashmemo(int, Date);
    void addItem(Saleline);
    void display();
};

#endif
