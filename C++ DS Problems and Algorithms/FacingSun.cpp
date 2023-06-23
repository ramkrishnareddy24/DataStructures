#include<bits/stdc++.h>
using namespace std;

int countBuildings(int arr[],int n)
{
		int res=1;
		int curr_max=arr[0];
	   	for(int i=1;i<n;i++)
	   	{
	   		if(arr[i]>curr_max)
	   		{
	   			res++;
	   			curr_max=arr[i];
	   		}
	   	}
	    return res;
}

int main()
{
	int arr[]={7,4,8,2,9};
	int n=sizeof(arr)/sizeof(int);
	cout<<countBuildings(arr,n);
	return 0;
}