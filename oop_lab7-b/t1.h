
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    string holderName;
    double balance;

public:
    BankAccount();
    BankAccount(string accNum, string name, double initialBalance);
    void deposit(double amount);
    void withdraw(double amount);
    void displayAccount();
};
