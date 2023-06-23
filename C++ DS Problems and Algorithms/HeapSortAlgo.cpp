#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
void maxHeapify(int arr[],int n,int i)
{
	int largest=i;
	int left=2*i+1,right=2*i+2;

	if(left<n && arr[left]>arr[largest])
		largest=left;
	if(right<n && arr[right]>arr[largest])
		largest=right;

	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		maxHeapify(arr,n,largest);
	}
}

void buildHeap(int arr[],int n)
{
	for(int i=(n-2)/2;i>=0;i--)
		maxHeapify(arr,n,i);
}

void HeapSort(int arr[],int n)
{
	buildHeap(arr,n);
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[i],arr[0]);
		maxHeapify(arr,i,0);
	}
}

int main()
{
	int arr[]={5,4,3,1,2,9,8,6,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	HeapSort(arr,n);

	for(int x:arr)
		cout<<x<<" ";
}