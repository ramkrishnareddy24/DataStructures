#include<iostream>
using namespace std;

int RecBSearch(int arr[],int low,int high,int x)
{
	if(low>high) return -1;
	int mid=(low+high)/2;
	if(arr[mid]<x)
		return RecBSearch(arr,mid+1,high,x);
	else if(arr[mid]>x)
		return RecBSearch(arr,low,mid-1,x);
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(int);
	int x=3;
	cout<<RecBSearch(arr,0,n-1,x);
	return 0;
}