#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n)
{
	int i,j;
	for(int i=0;i<n;i++){
		int min_ind=i;
		for(int j=i+1;j<n;j++)
			if(arr[j]<arr[min_ind])
				min_ind=j;
			swap(arr[min_ind],arr[i]);
	}

}

int main()
{
	int arr[]={2,1,0};
	int n=sizeof(arr)/sizeof(int);
	int i;

	selectionSort(arr,n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}






	return 0;
}