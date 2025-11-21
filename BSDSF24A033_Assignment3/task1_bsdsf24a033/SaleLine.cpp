#include <iostream>
#include "Saleline.h"

using namespace std;

Saleline::Saleline()
{
    product = "";
    quantity = 0;
    price = 0;
}

Saleline::Saleline(string p, int q, float pr)
{
    product = p;
    quantity = q;
    price = pr;
}

void Saleline::display()
{
    cout << "Product: " << product << ", Quantity: " << quantity << ", Price: " << price << endl;
}

float Saleline::getTotal()
{
    return quantity * price;
}
