#include "payroll.h"
#include "officer.h"
#include "dailywager.h"
#include <iostream>
using namespace std;

int main()
{
    Payroll payroll;

    Employee *e1 = new Officer("Ahsan Javed", "IT", 18, 95000);
    Employee *e2 = new DailyWager("Bilal Khan", "Maintenance", 6, 1000, 1);
    Employee *e3 = new DailyWager("Maria Iqbal", "Logistics", 7, 1200, 0);

    payroll.addEmployee(e1);
    payroll.addEmployee(e2);
    payroll.addEmployee(e3);

    cout << "=== Monthly Payroll Report ===\n";
    payroll.printSalaries();
    system("pause");


    return 0;
}
