#include <iostream>
#include <iomanip>
using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
};

class Rect : public Shape
{
    float l, w;

public:
    Rect(float x, float y)
    {
        l = x;
        w = y;
    }
    float area()
    {
        return l * w;
    }
    void show()
    {
        cout << "Rectangle\t" << fixed << area() << "\tLength:" << l << ", Width:" << w << endl;
    }
};

class Circ : public Shape
{
    float r;

public:
    Circ(float x)
    {
        r = x;
    }
    float area()
    {
        return 3.14 * r * r;
    }
    void show()
    {
        cout << "Circle\t\t" << fixed << area() << "\tRadius:" << r << endl;
    }
};

int main()
{
    Shape *s[6];
    s[0] = new Circ(4.5);
    s[1] = new Circ(0.015);
    s[2] = new Rect(3.25, 1.8);
    s[3] = new Rect(2, 2);
    s[4] = new Circ(2);
    s[5] = new Rect(1, 5);

    cout << "Sr#\tType\t\tArea\t\tData" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << "\t";
        if (Circ *c = dynamic_cast<Circ *>(s[i]))
            c->show();
        else if (Rect *r = dynamic_cast<Rect *>(s[i]))
            r->show();
    }
}
