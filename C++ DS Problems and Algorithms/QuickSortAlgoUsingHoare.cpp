#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
int HoareParition(int arr[],int l,int h)
{
	int p=arr[l];
	int i=l-1,j=h+1;

	while(true)
	{
		do
		{
			i++;
		}while(arr[i]<p);

		do
		{
			j--;
		}while(arr[j]>p);

		if(i>=j) return j;
		swap(arr[i],arr[j]);
	}
}

void QuickSort(int arr[],int l,int h)
{
	if(l<h)
	{
		int p=HoareParition(arr,l,h);
		QuickSort(arr,l,p);
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