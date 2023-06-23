#include<bits/stdc++.h>
using namespace std;

int findClosestNumber(int arr[],int n) {
    // int n = arr.size();
    int res = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(abs(arr[i])==abs(res))
        res = max(res,arr[i]);
        else if(abs(arr[i])<abs(res))
            res=arr[i];
    }
    return res;
}

int main()
{
    int arr[] = {-100000,-100000};
    int n = sizeof(arr)/sizeof(int);
    cout<<findClosestNumber(arr,n);
}