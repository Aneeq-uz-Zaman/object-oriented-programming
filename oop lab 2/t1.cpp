#include <iostream>
using namespace std;

class Matrix33
{
protected:
    double m[3][3];
public:

    double getElement(int row,int col)
    {
        return m[row][col];
    }

    void setElement(int row,int col,double val)
    {
        m[row][col]=val;
    }

    void setter(int a[3][3])
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
                m[i][j]=a[i][j];
                }
        }

    }
    void output()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
                cout<<m[i][j]<<" ";
                }
            cout<<endl;
        }
    }

};


int main()
{
    Matrix33 x;
    double a[3][3];

    for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
                a[i][j]=100;
                }
            cout<<endl;
        }
    x.setter(a);

    x.output();

    return 0;
}
