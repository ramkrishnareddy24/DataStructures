#include<iostream>
using namespace std;
class Numbers
{
    int x,y,z;
public:
    void setxyz(int ,int ,int);
    friend class Calculation;
};

void Numbers::setxyz(int a,int b,int c)
{
    x=a;
    y=b;
    z=c;
}

class Calculation
{
public:
    int findmin(Numbers n);
};

int Calculation::findmin(Numbers n)
{
    if(n.x<n.y && n.x<n.z)
        return n.x;
    if(n.y<n.x && n.y<n.z)
        return n.y;
    else
        return n.z;
}
int main()
{
    Numbers n1;
    n1.setxyz(10,20,30);

    Calculation cal;
    int res=cal.findmin(n1);
    cout<<"The minimum  is ="<<res<<endl;
}
