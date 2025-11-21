#include <iostream>
using namespace std;

class Complex {
public:
    int real;  // Real part
    int imag;  // Imaginary part

    // Constructor to initialize complex numbers
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real; // Add the real parts
        temp.imag = imag + obj.imag; // Add the imaginary parts
        return temp;
    }

    // Function to display the complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);

    // Using overloaded '+' operator
    Complex c3 = c1 + c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Sum: ";
    c3.display();

    return 0;
}
