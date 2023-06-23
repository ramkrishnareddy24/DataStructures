#include<iostream>
#include<conio.h>
using namespace std;

class Matrix
{
    int mat[10][10];
    int m,n;
public:
    void setsize(int x,int y)
    {
        m=x;
        n=y;
    }
    void get()
    {

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin>>mat[i][j];
            }
        }
    }
    void display()
    {
        cout<<"Matrix Elements :"<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
            cout<<" "<<mat[i][j];
            }cout<<endl;
        }
    }

    friend Matrix transpose(Matrix);
};

Matrix transpose(Matrix m1)
{
    int m,n;
    Matrix tmat;
    tmat.setsize(m1.m,m1.n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            {
                tmat.mat[j][i]=m1.mat[i][j];

            }
    }
   return tmat;
}

int main()
{
    Matrix m1;
    int m,n;
    cout<<"Enter order of Matrix"<<endl;
    cout<<"Row:";
    cin>>m;
    cout<<"Coln:";
    cin>>n;
    m1.setsize(m,n);
    m1.get();
    m1.display();
    cout<<endl;
    Matrix m2;
    m2=transpose(m1);
    m2.display();
    getch();
}
