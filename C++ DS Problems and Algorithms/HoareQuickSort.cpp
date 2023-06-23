#include<iostream>
using namespace std;

int HoarePartition(int arr[],int l,int h)
{
	int pivot=arr[l];
	int i=l-1,j=h+1;

	while(true)
	{
		do
		{
			i++;
		}while(arr[i]<pivot);

		do
		{
			j--;
		}while(arr[j]>pivot);

		if(i>=j) return j;
		swap(arr[i],arr[j]);
	}
}

void quickSort(int arr[],int l,int h)
{
	if(l<h)
	{
		int p=HoarePartition(arr,l,h);
		quickSort(arr,l,p);
		quickSort(arr,p+1,h);
	}
}

int main()
{
	int arr[]={2, 1, 6, 10, 4, 1, 3, 9, 7};
	int n=sizeof(arr)/sizeof(int);
	int i,j,l=0,h=n-1;

	quickSort(arr,l,h);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}


	return 0;
}