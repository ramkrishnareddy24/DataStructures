#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int m,int n)
{
	int i=n-1,j=0;

	while(i>=0 && j<n)
	{
		if(arr1[i]>arr2[j])
		{
			swap(arr1[i],arr2[j]);
			i--;
			j++;
		}
		else
		{
			j++;
		}
	}
	sort(arr1,arr1+m);
	sort(arr2,arr2+n);
}

int main()
{
	int arr1[]={1 ,4 ,8 ,10};
	int arr2[]={2 ,3 ,9};
	int m=sizeof(arr1)/sizeof(int);
	int n=sizeof(arr2)/sizeof(int);

	merge(arr1,arr2,m,n);

	for(int i=0;i<m;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr2[i]<<" ";

	return 0;
}