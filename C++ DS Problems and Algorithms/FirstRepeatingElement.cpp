#include<bits/stdc++.h>
using namespace std;

int firstRepeating(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			if(arr[j]==arr[i])
				return i;
		}
	}
	return -1;
}

int main()
{
	int arr[]={1,1,2,2,3,3};
	int n=sizeof(arr)/sizeof(int);
	cout<<firstRepeating(arr,n);
	return 0;
}