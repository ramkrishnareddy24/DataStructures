#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[],int n,int i)
{
	int largest=i,left=2*i+1,right=2*i+2;
	if(left<n && arr[left]>arr[largest]) largest=left;
	if(right<n && arr[right]>arr[largest]) largest=right;

	if(largest!=i)
	{
		swap(arr[largest],arr[i]);
		maxHeapify(arr,n,largest);
	}
}

void buildHeap(int arr[],int n)
{
	for(int i=(n-2)/2;i>=0;i--)
	{
		maxHeapify(arr,n,i);
	}
}

int HeapSort(int arr[],int n)
{
	buildHeap(arr,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(arr[0],arr[i]);
		maxHeapify(arr,i,0);
	}
}


int main()
{
	int arr[]={3,4,5,1,2,6,8,9,11,10};
	int n=sizeof(arr)/sizeof(int);

	HeapSort(arr,n);

	for(auto x:arr)
	{
		cout<<x<<" "; 
	}
}