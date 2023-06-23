#include<bits/stdc++.h>
#include<stack>
using namespace std;

int secondLar(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max) max=arr[i];
    }

    int sL=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>sL && arr[i]!=max) sL=arr[i];
    }

    return sL;
}

int consecOnes()
{
    int cnt=0;
    int res=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            cnt++;
        }
        else
        {
            res=max(res,cnt);
            cnt=0;
        }
    }
    return res;
}

int main()
{
    int arr[]={1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,0,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);


    int res = consecOnes(arr,n,1);
    cout<<res;

    return 0;
}



// Consecutive Maximum Ones:
// Input : arr[]={1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,0,1,1,1};
// key x=1;

// output: 5