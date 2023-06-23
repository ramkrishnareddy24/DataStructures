#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
	int n1=m-l+1,n2=r-m;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)
	{
		left[i]=arr[l+i];
	}
	for(int j=0;j<n2;j++)
	{
		right[j]=arr[m+j+1];
	}

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

void mergeSort(int arr[],int l,int r)
{
	if(r>l)
	{
		int m=l+(r-l)/2;
		mergeSort(arr,l,r);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main()
{
	int arr[]={5,6,7,8,3,5,6,1};
	int n=sizeof(arr)/sizeof(int);
	int l=0,r=n-1;

	mergeSort(arr,l,r);

	for(auto x:arr)
		cout<<x<<" ";
}