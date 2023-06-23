#include<bits/stdc++.h>
using namespace std;

//Merge Function
void merge(int arr[],int l,int m,int r)
{
	int n1=m-l+1,n2=r-m;

	int left[n1];
	int right[n2];

	for(int i=0;i<n1;i++)
		left[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		right[j]=arr[m+1+j];

	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
			arr[k++]=left[i++];
		else
			arr[k++]=right[j++];
	}

	while(i<n1) arr[k++]=left[i++];
	while(j<n2) arr[k++]=right[j++];
}
//MergeSort
void MergeSort(int arr[],int l,int r)
{
	if(r>l)
	{
		int m=l+(r-l)/2;
		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main()
{
	int arr[]={20,10,5,80,50,70,60};
	int n=sizeof(arr)/sizeof(arr[0]);
	int l=0,r=n-1;
	MergeSort(arr,l,r);

	for(int x:arr)
		cout<<x<<" ";

	return 0;
}