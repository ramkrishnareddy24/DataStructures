#include<iostream>
using namespace std;

class A
{
public:
    A(){
    cout<<"Called A constructor"<<endl;
    }
    virtual ~A()
    {
        cout<<"Called A destructor"<<endl;
    }
};

class B:public A
{
    int *num;
public:
    B()
    {
        num=new int(100);
        cout<<"Called B constructor"<<endl;
    }
    ~B()
    {
        delete num;
        cout<<"called B constructor"<<endl;
    }
};

int main()
{
    cout<<"When object and class pointer are of same type"<<endl;
    B *bptr= new B;
    delete bptr;

    cout<<"When derived class object is pointed at by base class pointer "<<endl;
    A *aptr = new B;
    delete aptr;
    return 0;
}
