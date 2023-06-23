#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[]={20,30,40,40,40,50,100,1100};
    int n=sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    bool present = binary_search(arr,arr+n,key);
    if(present)
    {
        cout<<"Present"<<endl;

    }
    else
    {
        cout<<"Absent";
    }


    auto lb=lower_bound(arr,arr+n,key);
    cout<<"lower bound is"<<(lb-arr)<<endl;
    if((lb-arr)==n)
    {
        cout<<"Element is not Present";
    }

    auto up=upper_bound(arr,arr+n,key);
    cout<<"upper bound is"<<(up-arr)<<endl;

    cout<<"Occ freq of 40 is "<<(up-lb)<<endl;


    return 0;
}

