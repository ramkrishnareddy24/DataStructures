#include<iostream>
using namespace std;
int r,n;

class mat
{
    int m[10][10];
    
    public:
    void inp()
    {
        int i,j;
        cout<<"enter number of rows"<<endl;
        cin>>r;
        cout<<"enter number  of columns:"<<endl;
        cin>>n;
        cout<<"enter the elements"<<endl;
        for (i=0;i<r;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>m[i] [j];
            }
        }
    }
    void outp()
        {
        int i,j;
        for(i=0;i<r;i++)
        {
           cout<<endl;
            for(j=0;j<n;j++)
            {
                cout<<m[i][j];
                cout<<"\t";
            }
        }
    }
    friend mat tp(mat);
    
};
mat tp (mat m1)
{
    mat temp;
    int i,j;
    cout<<"the transpose of a matrix is"<<endl;
    for (i=0;i<r;i++)
    {
        for(j=0;j<n;j++)
        {
            
            temp.m[i][j]=m1.m[j][i];
            
        }
    }
    return temp;
}

int main()
{
    mat m1,m2;
    m1.inp();
    m1.outp();
    m2=tp(m1);
    m2.outp();
    
    
}
