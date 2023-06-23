#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}

int main()
{
	int arr[]={100,25,125,60,70,90};
	int n=sizeof(arr)/sizeof(arr[0]);

	bubbleSort(arr,n);

	for(auto x:arr)
	{
		cout<<x<<" ";
	}
}