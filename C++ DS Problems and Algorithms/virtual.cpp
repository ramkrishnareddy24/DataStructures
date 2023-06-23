#include<iostream>
#include<cstring>
using namespace std;

class student
{
    string name;
public:
    virtual void iam()
    {
        cout<<"I am a student"<<endl;
    }
    string getname()
    {
        return name;
    }
};

class ISEstudent:public student
{
public:
    void iam()
    {
        cout<<"I am an ISE student"<<endl;
    }
};

class ISE4thsemstudent:public ISEstudent
{
public:
    void iam()
    {
        cout<<"I am an ISE 4th sem student "<<endl;
    }
};

int main()
{
    ISE4thsemstudent i4;
    ISEstudent *iptr=&i4;
    iptr->iam();
}
