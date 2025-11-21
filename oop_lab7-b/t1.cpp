// Task 2: Bank Account Simulation (50 marks)
// Create a class BankAccount with:

// Private data members: accountNumber, holderName, balance

// Constructor, deposit(), withdraw(), displayAccount()

// Function to check for insufficient balance.

// main.cpp should:

// Create 2 accounts.

// Perform deposits and withdrawals.

// Display final balance with appropriate messages.
#include <iostream>
#include "t1.h"
#include <string>
using namespace std;

BankAccount::BankAccount() : accountNumber(""), holderName(""), balance(0.0) {}

BankAccount::BankAccount(string accNum, string name, double initialBalance) : accountNumber(accNum), holderName(name), balance(initialBalance) {}

void BankAccount::deposit(double amount)
{
    balance = balance + amount;
    cout << "Deposited: $" << amount << endl;
}
void BankAccount::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance = balance - amount;
        cout << "Withdrawn: $" << amount << endl;
    }
    else
    {
        cout << "Insufficient balance for withdrawal." << endl;
    }
}

void BankAccount::displayAccount()
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << holderName << endl;
    cout << "Balance: $" << balance << endl;
}