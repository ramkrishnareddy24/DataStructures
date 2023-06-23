#include<iostream>
using namespace std;

class matrix
{
    int a[100][100];
    int m,n;
    friend void transpose(matrix m);
    //int t[100][100];
public:
    void read()
    {
        cout<<"Enter the order of matrix"<<endl;
        cin>>m>>n;
        cout<<"Enter the elements in matrix"<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
    }
    void print()
    {
        cout<<"The Matrix is"<<endl;
        for (int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<endl;
            }
        }
    }
   //friend void transpose(matrix m);
};
void transpose(matrix m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[j][i]<<endl;
        }
    }
}
int main()
{
    matrix m1;
    m1.read();
    m1.print();
    cout<<"Transpose"<<endl;
    m1.transpose()
}
