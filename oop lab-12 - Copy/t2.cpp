#include<iostream>
using namespace std;

class Geo {
public:
    virtual float len() = 0;
};

class Box : public Geo {
    float a, b;
public:
    Box(float x, float y) {
        a = x; b = y;
    }
    float len() {
        return 2 * (a + b);
    }
    float calc() {
        return a * b;
    }
};

class Round : public Geo {
    float r;
public:
    Round(float z) {
        r = z;
    }
    float len() {
        return 2 * 3.14 * r;
    }
    float calc() {
        return 3.14 * r * r;
    }
};

class Three : public Geo {
    float u, v, w;
public:
    Three(float x, float y, float z) {
        u = x; v = y; w = z;
    }
    float len() {
        return u + v + w;
    }
};

class Stick : public Geo {
    float p;
public:
    Stick(float k) {
        p = k;
    }
    float len() {
        return p;
    }
};

int main() {
    Geo* d[4];
    d[0] = new Box(5, 6);
    d[1] = new Round(3);
    d[2] = new Three(2, 3, 4);
    d[3] = new Stick(12);
    for(int i = 0; i < 4; i++) {
        cout << d[i]->len() << endl;
    }
}
