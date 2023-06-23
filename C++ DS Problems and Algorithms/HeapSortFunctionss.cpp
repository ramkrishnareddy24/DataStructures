#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[],int n,int i)
{
	int largest=i,left=2*i+1,right=2*i+2;

	if(n<left && arr[left]>arr[largest])
		largest=left;
	if(n<right && arr[right]>arr[largest])
		largest=right;

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

int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);

	buildHeap(arr,n);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}


	return 0;
}