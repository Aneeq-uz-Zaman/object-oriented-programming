#include <iostream>
#include "t1.h"
#include <string>
using namespace std;

int main()
{
    BankAccount account[2];
    account[0] = BankAccount("123456", "Alice", 1000.0);
    account[1] = BankAccount("654321", "Bob", 500.0);
    account[0].displayAccount();
    cout << endl;
    account[0].deposit(200.56);
    account[0].withdraw(50.45);
    account[0].withdraw(1200.223);
    account[0].displayAccount();
    cout << endl;
    account[1].displayAccount();
    cout << endl;
    account[1].deposit(300.23);
    account[1].withdraw(100.2343);
    account[1].withdraw(800.23);
    account[1].displayAccount();
    return 0;
}
