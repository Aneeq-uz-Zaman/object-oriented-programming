#include <iostream>
#include <string>
using namespace std;

class Painting
{
protected:
    string t, a;
    float v;

public:
    Painting(string x, string y)
    {
        t = x;
        a = y;
        v = 400;
    }
    virtual void show()
    {
        cout << t << ", " << a << ", $" << v << endl;
    }
};

class FamousPainting : public Painting
{
public:
    FamousPainting(string x, string y) : Painting(x, y)
    {
        v = 25000;
    }
};

int main()
{
    Painting *arr[7];
    string t, a;
    for (int i = 0; i < 7; i++)
    {
        cout << "Title: ";
        getline(cin, t);
        cout << "Artist: ";
        getline(cin, a);
        if (a == "Degas" || a == "Monet" || a == "Picasso" || a == "Rembrandt")
            arr[i] = new FamousPainting(t, a);
        else
            arr[i] = new Painting(t, a);
    }
    for (int i = 0; i < 7; i++)
        arr[i]->show();
}
