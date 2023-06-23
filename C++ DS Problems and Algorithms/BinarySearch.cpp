#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int x)
{
	int low=0,high=n-1;

	while(low<=high)
	{
		int mid=(high+low)/2;
		if(arr[mid]==x)
			return mid;
		if(arr[mid]<x)
			low=mid+1;
		else
			high=mid-1;
	}	

	return -1;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int x=4;
	int n=sizeof(arr)/sizeof(int);
	cout<<BinarySearch(arr,n,x);
}