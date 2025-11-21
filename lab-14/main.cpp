#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MException33 : public exception {
    string msg;
    int code;
public:
    MException33(string m, int c): msg(m), code(c) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }

    int getCode() const {
        return code;
    }
};

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0): real(r), imag(i) {}

    Complex operator+(const Complex& rhs) const {
        return Complex(real + rhs.real, imag + rhs.imag);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }
};


class Rational {
public:
    int numerator, denominator;

    Rational(int n = 0, int d = 1): numerator(n), denominator(d) {
        if (d == 0) throw runtime_error("Denominator cannot be zero");
    }

    Rational operator+(const Rational& rhs) const {
        return Rational(numerator * rhs.denominator + rhs.numerator * denominator,
                        denominator * rhs.denominator);
    }

    friend ostream& operator<<(ostream& os, const Rational& r) {
        os << r.numerator << "/" << r.denominator;
        return os;
    }
};


class Vector3 {
public:
    double x, y, z;

    Vector3(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& rhs) const {
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    friend ostream& operator<<(ostream& os, const Vector3& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
};



template <typename T>
class Matrix33 {
protected:
    T data[3][3];
public:
    Matrix33() {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                data[i][j] = T();
    }

    void set(int row, int col, T val) {
        if(row < 0 || row >= 3 || col < 0 || col >= 3)
            throw ("Index out of bounds");
        data[row][col] = val;
    }

    T get(int row, int col) const {
        if(row < 0 || row >= 3 || col < 0 || col >= 3)
            throw MException33("Index out of bounds", 102);
        return data[row][col];
    }

    virtual void display() const {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j)
                cout << data[i][j] << "\t";
            cout << "\n";
        }
    }
};


template <typename T>
class Null33 : public Matrix33<T> {
public:
    Null33() {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                this->data[i][j] = T(); 
    }
    void display() const override{
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j)
                cout << this->data[i][j] << "\t";
            cout << "\n";
        }
    }
};


template <typename T>
class Identity33 : public Matrix33<T> {
public:
    Identity33() {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                this->data[i][j] = (i == j) ? T(1) : T();
    }
    void display() const override{
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j)
                cout << this->data[i][j] << "\t";
            cout << "\n";
        }
    }
};

int main() {
    try {

        Matrix33<int> mInt;
        mInt.set(0, 0, 5);
        mInt.set(1, 1, 10);
        mInt.set(2, 2, 15);
        cout << "Integer Matrix:\n";
        mInt.display();


        Matrix33<float> mFloat;
        mFloat.set(0, 1, 1.5);
        mFloat.set(1, 2, 2.5);
        cout << "\nFloat Matrix:\n";
        mFloat.display();


        Matrix33<Complex> mComplex;
        mComplex.set(0, 0, Complex(1, 2));
        mComplex.set(1, 1, Complex(3, -4));
        cout << "\nComplex Matrix:\n";
        mComplex.display();


        Matrix33<Rational> mRational;
        mRational.set(0, 0, Rational(1, 2));
        mRational.set(1, 1, Rational(3, 4));
        cout << "\nRational Matrix:\n";
        mRational.display();

        Matrix33<Vector3> mVector;
        mVector.set(0, 0, Vector3(1, 2, 3));
        mVector.set(1, 1, Vector3(4, 5, 6));
        cout << "\nVector Matrix:\n";
        mVector.display();

        Null33<int> mNull;
        cout << "\nNull Matrix:\n";
        mNull.display();

        Identity33<int> mId;
        cout << "\nIdentity Matrix:\n";
        mId.display();


    } catch (const MException33& e) {
        cout << "MException33 caught: " << e.what() << " Code: " << e.getCode() << endl;
    } catch (const exception& e) {
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
