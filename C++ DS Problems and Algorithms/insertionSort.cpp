#include<iostream>
using namespace std;

void insertionSort(int arr[],int n)
{
	for(int i=1;i<n;i++)
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
	int arr[]={9,8,7,6,5,4,2,3,1};    
	int n=sizeof(arr)/sizeof(int);
	int i;

	insertionSort(arr,n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

// void insertionSort(int arr[],int n)
// {
// 	for(int i=1;i<n;i++)
// 	{
// 		int key=arr[i],j=i-1;
// 		while(j>=0 && arr[j]>key)
// 		{
// 			arr[j+1]=arr[j];
// 			j--;
// 		}
// 		arr[j+1]=key;
// 	}
// }