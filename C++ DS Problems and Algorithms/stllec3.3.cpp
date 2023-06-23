#include<iostream>
#include<algorithm>
using namespace std;

//Define a comparator fn
bool compare(int a,int b)
{
    cout<<"Comparing "<<a<<"and"<<b<<endl;
    return a>b;
}

int main()
{
    int n,key;
    cin>>n;
    cout<<endl;

    int a[1000];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // Sort an array using sort()
    sort(a,a+n,compare);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }
}
