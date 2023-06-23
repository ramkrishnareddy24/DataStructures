#include <iostream>
#include<cstring>
using namespace std;
//nationality-indian age -18
void checknationality(string nationality)
    {
        if(nationality!="indian")
        {
           // throw "exception you cannot vote since you are not indian";
            throw "exception you cannot vote since you are a "+nationality;
        }
    }
void checkage(int age)
    {
       // string str;
        if(age<18)
        {
            //str=to_string(age);
            
            //throw "underage exception-you cannot vote since you are not 18 ";
            throw "under age exception -you cannot vaue since you are" + to_string(age) + "year old\nYou Need to wait another"+to_string(18-age)+"years to cast you vote";
        }
    }
int main()
{
    string nationality;
    int age;
    cout<<"enter your nationality"<<endl;
    cin>>nationality;
    try
    {
        checknationality(nationality);
        cout<<"enter your age"<<endl;
          cin>>age;
          checkage(age);
          cout<<"go ahaed and cost your vote"<<endl;
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
    catch(string e)
    {
        cout<<e<<endl;
    }
}