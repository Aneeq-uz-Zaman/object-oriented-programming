#ifndef SALELINE_H
#define SALELINE_H

#include <string>

using namespace std;

class Saleline
{
private:
    string product;
    int quantity;
    float price;

public:
    Saleline();
    Saleline(string, int, float);
    void display();
    float getTotal();
};

#endif
