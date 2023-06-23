#include<iostream>
using namespace std;
class FriendDemo
{
    int x,y;
    friend int sum(FriendDemo);
public:
    void set(int a,int b)
    {
        x=a;
        y=b;

    }

};
int sum(FriendDemo obj)
{
    return (obj.x)+(obj.y);

}
int main()
{
    FriendDemo obj1;
    obj1.set(9,8);
    int res=sum(obj1);
    cout<<"The res ="<<res<<endl;
}
