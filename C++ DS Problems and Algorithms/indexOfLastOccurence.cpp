#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int lastOccurenceNaive(int arr[],int n,int x)
{
	for(int i=n-1;i>=0;i--)
		if(arr[i]==x)
			return i;
	return -1;
}

//Efficient Recursive Solution
int lastOccurenceRecursive(int arr[],int low,int high,int x,int n)
{
	if(low>high)
		return -1;

	int mid=(low+high)/2;
	if(arr[mid]>x)
		return lastOccurenceRecursive(arr,low,mid-1,x,n);
	else if(arr[mid]<x)
		return lastOccurenceRecursive(arr,mid+1,high,x,n);
	else
	{
		if(mid==n-1 || arr[mid+1]!=arr[mid])
			return mid;
		else
			low=mid+1;
	}
}

//Iterative
//Efficient Solution
int lastOccurenceIterative(int arr[],int n,int x)
{
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]>x)
			high=mid-1;
		else if(arr[mid]<x)
			low=mid+1;
		else
		{
			if(mid==n-1 || arr[mid+1]!=arr[mid])
				return mid;
			else
				low=mid+1;
		}
	}
}

int main()
{
	int arr[]={1,7,8,8,8,8,8,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	int low=0;
	int high=n-1;
	cout<<lastOccurenceNaive(arr,n,8)<<" ";
	cout<<lastOccurenceRecursive(arr,low,high,8,n)<<" ";
	cout<<lastOccurenceIterative(arr,n,8);
	return 0;
}