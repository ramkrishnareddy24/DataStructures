#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LomutoPartition(int arr[],int l,int h)
{
	int pivot=arr[h];
	int i=l-1;

	for(int j=l;j<=h-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return(i+1);
}

int main()
{
	int arr[]={10,80,30,40,50,90,70};
	int l=0,n=sizeof(arr)/sizeof(int);
	int h=n-1;

	LomutoPartition(arr,l,h);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}