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
    Matrix33 multiply(int scalar)
    {
        Matrix33 r;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
                r.m[i][j]=m[i][j]*scalar;
                }
        }
        return r;

    }
    double determinant()    {
        return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
               m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
               m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    }
    bool equal(Matrix33 o)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
                if(o.m[i][j]!=m[i][j])
                    return false;
                }
        }
        return true;
    }

};


int main()
{
    Matrix33 x(3);


    Matrix33 w(8);


    cout<<x.equal(w);




    return 0;
}
