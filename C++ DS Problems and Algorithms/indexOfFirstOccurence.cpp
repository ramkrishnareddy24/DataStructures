#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int firstOccurenceNaive(int arr[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==x)
			return i;
	}
	return -1;
}

//Efficient Recursive Solution
int firstOccurenceRecursive(int arr[],int low,int high,int x)
{
	if(low>high)
		return -1;

	int mid=(low+high)/2;
	if(arr[mid]>x)
		return firstOccurenceRecursive(arr,low,mid-1,x);
	else if(arr[mid]<x)
		return firstOccurenceRecursive(arr,mid+1,high,x);
	else
	{
		if(mid==0 || arr[mid-1]!=arr[mid])
			return mid;
		else
			high=mid-1;
	}
}

//Efficient Iterative Solution better than Recursive
int firstOccurenceIterative(int arr[],int n,int x)
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
			if(mid==0 || arr[mid-1]!=arr[mid])
				return mid;
			else
				high=mid-1;
		}
	}
}

int main()
{
	int arr[]={5,10,10,15,20,20,20};
	int n=sizeof(arr)/sizeof(arr[0]);
	int low=0,high=n-1;
	cout<<firstOccurenceNaive(arr,n,20)<<" ";
	cout<<firstOccurenceRecursive(arr,low,high,20)<<" ";
	cout<<firstOccurenceIterative(arr,n,20);
	return 0;
}