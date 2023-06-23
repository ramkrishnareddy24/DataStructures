#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
int lomutoPartition(int arr[],int l,int h)
{
	int p=arr[h];
	int i=l-1;

	for(int j=l;j<=h;j++)
	{
		if(arr[j]<p)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;
}

void QuickSort(int arr[],int l,int h)
{
	if(l<h)
	{
		int p=lomutoPartition(arr,l,h);
		QuickSort(arr,l,p-1);
		QuickSort(arr,p+1,h);
	}
}

int main()
{
	int arr[]={10,80,30,90,40,50,70};
	int n=sizeof(arr)/sizeof(arr[0]);
	int l=0,h=n-1;
	QuickSort(arr,l,h);

	for(int x:arr)
		cout<<x<<" ";
}