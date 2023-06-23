#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;

	int L[n1],R[n2];

	for(int i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		R[j]=arr[m+1+j];

	i=0;j=0;k=l;

	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
	}
}

int mergerSort(int arr[],int l,int r)
{
	if(r>l)
	{
		int m=l+(r-l)/2;
		mergerSort(arr,l,m);
		mergerSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main()
{
	int arr[]={1,5,2,5,4,3,2,6,9};
	int n=sizeof(arr)/sizeof(int);
	int i,l=0;

	mergerSort(arr,l,n);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}