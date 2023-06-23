#include<iostream>
#include<conio.h>
using namespace std;

class Time
{
    long int hh,mm,ss;
public:
    void get(int h,int m,int s)
    {
        hh=h;
        mm=m;
        ss=s;

    }
    void put()
    {
        cout<<endl<<hh<<":"<<mm<<":"<<ss;
    }
    friend Time add(Time ,Time );
};

Time add(Time t1,Time t2)
{
    Time t;
    t.hh=t1.hh+t2.hh;
    t.mm=t1.mm+t2.mm;
    t.ss=t1.ss+t2.ss;

    if(t.mm>=60)
    {
        t.hh++;
        t.mm=t.mm-60;
        t.mm=t.mm;
    }
    if(t.ss>=60)
    {
        t.mm++;
        t.ss=t.ss-60;
        t.ss=t.ss;
    }
    return(t);
}

int main()
{
    Time obj1,obj2,obj3;


    obj1.get(1,40,31);
    obj2.get(1,30,45);
    obj1.put();
    obj2.put();

    cout<<endl<<"--------";
    obj3=add(obj1,obj2);
    obj3.put();
    getch();
}

