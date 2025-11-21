#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function (no implementation here)
    virtual void draw() = 0;

    // Virtual destructor (important for abstract classes)
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle." << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle." << endl;
    }
};

int main() {
    // Creating objects using pointers to the base class
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    // Call the draw() method
    shape1->draw(); // Output: Drawing a Circle.
    shape2->draw(); // Output: Drawing a Rectangle.

    // Clean up
    delete shape1;
    delete shape2;

    return 0;
}
