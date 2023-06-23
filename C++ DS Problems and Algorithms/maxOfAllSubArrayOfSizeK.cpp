#include<bits/stdc++.h>
using namespace std;

void maxofsubarrays(int arr[],int n,int k)
{
		int curr=0;
        for(int i=0;i<k;i++)
        {
            curr=max(curr,arr[i]);    
        }
        cout<<curr<<" ";
        int max_val=curr;

        for(int i=k;i<n;i++){
            max_val=max(max_val,arr[i]);
            cout<<max_val<<" ";
        }
}

int main()
{
	int arr[]={1 ,2 ,3 ,1 ,4 ,5 ,2 ,3 ,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	maxofsubarrays(arr,n,k);
}