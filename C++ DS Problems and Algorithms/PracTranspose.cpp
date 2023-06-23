#include <iostream>
using namespace std;
class matrix
{
  int r,c;
  int m[10][10];
  public:
  void get()
  {
    int i,j;
    cout<<"Enter MAtrix Ele"<<endl;
    cout<<"enter row:"; cin>>r;
    cout<<"enter col:"; cin>>c;
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
      {
        cin>>m[i][j];
      }
    }
  }
  void display()
  {
    int i,j;
    cout<<"Matrix "<<endl;
    for(i=0;i<c;i++)
    {
      for(j=0;j<r;j++)
      {
        cout<<m[i][j]<<" ";
      }cout<<endl;
    }
  }
  friend matrix transpose(matrix);
};
matrix transpose(matrix m1)
{
  matrix temp;
  int i,j;
   for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
      {
        temp.m[i][j]=m1.m[j][i];
      }
    }
  return temp;
}
int main() {
matrix m1,m2;
m1.get();
m1.display();
cout<<endl; 
m2=transpose(m1);
m2.display();
}