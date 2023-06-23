#include<iostream>
#include<algorithm>
using namespace std;

int HoarePartition(int arr[],int l,int h)
{
	int pivot=arr[l];
	int i=l-1;
	int j=h+1;
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

void QuickSort(int arr[],int l,int h)
{
	if(l<h)
	{
		int p=HoarePartition(arr,l,h);
		QuickSort(arr,l,p-1);
		QuickSort(arr,p+1,h);
	}
}

int main()
{
	int arr[]={5,3,8,4,2,7,1,10};
	int n=sizeof(arr)/sizeof(int);
	int l=0,h=n-1;

	QuickSort(arr,l,h);

	for(auto x:arr)
	{
		cout<<x<<" ";
	}
}