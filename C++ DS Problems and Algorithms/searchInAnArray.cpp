#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int n,int x)
{
	for(int i=0;i<n;i++)
		if(arr[i]==x)
			return i;
}

int main()
{
	int arr[]={1,5,7,10};
	int n=sizeof(arr)/sizeof(int);
	int x=7;
	cout<<search(arr,n,x);
}