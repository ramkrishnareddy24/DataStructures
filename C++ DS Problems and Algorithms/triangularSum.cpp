#include<bits/stdc++.h>
using namespace std;

void triangularSum(int arr[],int n)
{
	if(n<1) return;

	int barr[n-1];
	
	for(int i=0;i<n-1;i++)
	{
		int x=arr[i]+arr[i+1];
		barr[i]=x;
	}
	triangularSum(barr,n-1);
	
	// cout<<barr[0]<<" ";
	for(int i=0;i<n-1;i++)
		cout<<barr[0]<<" ";
}

void tri(int A[],int n)
{
	if (n < 1)
            return;
   
        
        int temp[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            int x = A[i] + A[i + 1];
            temp[i] = x;
        }
   
       
        tri(temp, n - 1);
   
        
        cout<<A[0]<<" ";      
        
}

int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	// tri(arr,n);
	triangularSum(arr,n);
}
