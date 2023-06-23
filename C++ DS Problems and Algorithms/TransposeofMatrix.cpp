#include<iostream>
using namespace std;

class Matrix
{
    int mat[10][10];
    
public:
    void get()
    {
        /*
        cout<<"Enter rows"<<endl;
        cin>>m;
        cout<<"Enter colns"<<endl;
        cin>>n;
        cout<<endl;
        */
        cout<<"Enter the matrix Elements"<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>mat[i][j];
            }
        }
    }
    void display()
    {
        cout<<"Matrix Elements :"<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++){
            cout<<" "<<mat[i][j];
            }cout<<endl;
        }
    }

    friend Matrix transpose(Matrix m1);
};

Matrix transpose(Matrix m1)
{
    Matrix tmat;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            {
                tmat.mat[i][j]=m1.mat[j][i];
            }
    }
    return m1;
}

int main()
{
    Matrix m1,m2;
    m1.get();

    //m1.display();
    cout<<endl;

    m2=transpose(m1);
    m2.display();
}