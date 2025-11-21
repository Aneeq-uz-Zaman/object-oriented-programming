#include <iostream>
using namespace std;

class Matrix33
{
protected:
    int m[3][3];
public:
    Matrix33()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
                m[i][j]=0.0;
                }
        }
    }
    Matrix33(int a)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
                m[i][j]=a;
                }
        }
    }
    double getElement(int row,int col)
    {
        return m[row][col];
    }
    void setElement(int row,int col,double val)
    {
        m[row][col]=val;
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


    //cout<<x.getElement(1,1);
    x.output();
    Matrix33 w(3);
    w.output();

    return 0;
}
