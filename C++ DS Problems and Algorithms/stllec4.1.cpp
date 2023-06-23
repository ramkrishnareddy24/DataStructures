#include<iostream>
using namespace std;

int main()
{
    //String INit
    string s0;
    string s1("Hello");

    string s2="Hello world";
    string s3(s2);

    string s4=s3;

    char a[]={'a','b','c','\0'};
    string s5(a);

    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;

    if(s0.empty()){
        cout<<"s0 is empty"<<endl;
    }

    s0.append("I love c++");
    cout<<s0<<endl;

    s0+=" and python";
    cout<<s0<<endl;
    //s0.clear();
    cout<<s0.length()<<endl;

    s0="Apple";
    s1="Mango";
    cout<<s0.compare(s1)<<endl;

    if(s1>s0)
    {
        cout<<"Mango is lexographially greater than Apple"<<endl;
        cout<<s1[0]<<endl;
    }
    //find
    string s="I want to have apple juice";
    int idx=s.find("apple");
    cout<<idx<<endl;

    //remove
    string word="apple";
    int len=word.length();
    cout<<s<<endl;
    s.erase(idx,len+1);
    cout<<s<<endl;

    //iterate over all the  characters
    for(int i=0;i<s1.length();i++)
    {
        cout<<s1[i]<<":";
    }

    //Iterators
    for(auto it=s1.begin();it!=s1.end();it++)
    {
        cout<<(*it)<<",";
    }

    //for each loop
    for(char c:s1)
    {
        cout<<c<<",";
    }

}

