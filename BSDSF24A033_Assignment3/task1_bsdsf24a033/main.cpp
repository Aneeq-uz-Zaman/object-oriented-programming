#include <iostream>
#include "Cashmemo.h"

using namespace std;

int main()
{
    Date d(11, 5, 2025);
    Cashmemo cm(1001, d);

    Saleline s1("Milk", 2, 50);
    Saleline s2("Bread", 1, 40);
    Saleline s3("Eggs", 12, 10);

    cm.addItem(s1);
    cm.addItem(s2);
    cm.addItem(s3);

    cm.display();

    return 0;
}
