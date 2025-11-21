#include<iostream>
#include<cmath>
using namespace std;

class Shape {
public:
    virtual float boundaryLength() = 0;
};

class Rect : public Shape {
    float l, w;
public:
    Rect(float x, float y) {
        l = x; w = y;
    }
    float boundaryLength() {
        return 2 * (l + w);
    }
    float area() {
        return l * w;
    }
};

class Circ : public Shape {
    float r;
public:
    Circ(float x) {
        r = x;
    }
    float boundaryLength() {
        return 2 * 3.14 * r;
    }
    float area() {
        return 3.14 * r * r;
    }
};

class Tri : public Shape {
    float a, b, c;
public:
    Tri(float x, float y, float z) {
        a = x; b = y; c = z;
    }
    float boundaryLength() {
        return a + b + c;
    }
};

class Line : public Shape {
    float l;
public:
    Line(float x) {
        l = x;
    }
    float boundaryLength() {
        return l;
    }
};

int main() {
    Shape* s[4];
    s[0] = new Rect(4, 5);
    s[1] = new Circ(3);
    s[2] = new Tri(3, 4, 5);
    s[3] = new Line(10);
    for(int i = 0; i < 4; i++) {
        cout << s[i]->boundaryLength() << endl;
    }
}
