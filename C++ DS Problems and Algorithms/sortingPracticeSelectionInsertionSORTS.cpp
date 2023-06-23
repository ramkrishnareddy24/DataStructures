#include<iostream>
using namespace std;

void selectionSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min_ind=i;
		for(int j=i+1;j<n;j++)
			if(arr[j]<arr[min_ind])
				min_ind=j;
			swap(arr[min_ind],arr[i]);
	}
}

void insertionSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main()
{
	int arr[]={9,8,7,6,84,5,64,12,11,10,1};
	int n=sizeof(arr)/sizeof(int);

	selectionSort(arr,n);
	for(auto x:arr)
	{
		cout<<x<<" ";
	}cout<<endl;
	insertionSort(arr,n);
	for(auto y:arr)
	{
		cout<<y<<" ";
	}
}