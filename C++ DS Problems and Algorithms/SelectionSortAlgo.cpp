#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void selectionSort(int arr[],int n)
{
	int temp[n];

	for(int i=0;i<n;i++)
	{
		int min_ind=0;
		for(int j=1;j<n;j++)
		{
			if(arr[j]<arr[min_ind])
				min_ind=j;
		}
		temp[i]=arr[min_ind];
		arr[min_ind]=INT_MAX;
	}
	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}

//Efficient Solution
void SelectionSort(int arr[],int n)
{
	int min_ind;
	for(int i=0;i<n-1;i++)
	{
		min_ind=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_ind])
				min_ind=j;
		}
		swap(arr[min_ind],arr[i]);
	}
}

int main()
{
	int arr[]={2,10,8,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	// selectionSort(arr,n);
	// cout<<endl;
	SelectionSort(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}