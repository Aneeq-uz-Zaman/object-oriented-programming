#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    double* v[25];

    for (int i = 0; i < 25; i++) {
        v[i] = new double[i + 1];
        for (int j = 0; j <= i; j++) {
            v[i][j] = rand() % 8 + 2;
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 25; i++) {
        delete[] v[i];
    }

    return 0;
}
