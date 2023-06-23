#include<bits/stdc++.h>
using namespace std;

int moveZero(int arr[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
		if(arr[i]!=0)
		{
			swap(arr[i],arr[count]);
			count++;
		}
}

int main()
{
	int arr[]={1,2,0,0,3};
	int n=sizeof(arr)/sizeof(int);
	moveZero(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}