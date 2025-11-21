#include<iostream>
#include<iomanip>
using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class Recta : public Base {
    float m, n;
public:
    Recta(float x, float y) {
        m = x; n = y;
    }
    float area() {
        return m * n;
    }
    void print() {
        cout << "Rectangle\t" << fixed << setprecision(2) << area() << "\tSize:" << m << "x" << n << endl;
    }
};

class Circa : public Base {
    float q;
public:
    Circa(float r) {
        q = r;
    }
    float area() {
        return 3.14 * q * q;
    }
    void print() {
        cout << "Circle\t\t" << fixed << setprecision(5) << area() << "\tRadius:" << q << endl;
    }
};

int main() {
    Base* b[6];
    b[0] = new Circa(4.5);
    b[1] = new Circa(0.015);
    b[2] = new Recta(3.25, 1.8);
    b[3] = new Recta(2.5, 2);
    b[4] = new Circa(2.25);
    b[5] = new Recta(1.1, 4.9);

    cout << "Sr#\tType\t\tArea\t\tInfo" << endl;
    for(int k = 0; k < 6; k++) {
        cout << k+1 << "\t";
        if(Circa* c = dynamic_cast<Circa*>(b[k])) c->print();
        else if(Recta* r = dynamic_cast<Recta*>(b[k])) r->print();
    }
}
