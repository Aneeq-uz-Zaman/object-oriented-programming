#include <iostream>
#include <string>
using namespace std;

class Art
{
protected:
    string s1, s2;
    float price;

public:
    Art(string x, string y)
    {
        s1 = x;
        s2 = y;
        price = 400;
    }
    virtual void show()
    {
        cout << s1 << ", " << s2 << ", $" << price << endl;
    }
};

class BigArt : public Art
{
public:
    BigArt(string x, string y) : Art(x, y)
    {
        price = 25000;
    }
};

int main()
{
    Art *list[7];
    string x, y;
    for (int j = 0; j < 7; j++)
    {
        cout << "Enter title: ";
        getline(cin, x);
        cout << "Enter artist: ";
        getline(cin, y);
        if (y == "Degas" || y == "Monet" || y == "Picasso" || y == "Rembrandt")
            list[j] = new BigArt(x, y);
        else
            list[j] = new Art(x, y);
    }
    for (int j = 0; j < 7; j++)
        list[j]->show();
}
