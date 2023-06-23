#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bucketSort(int arr[],int n,int k)
{
	int i,maxval=arr[0];
	for(int i=1;i<n;i++)
	{
		maxval=max(maxval,arr[i]);
	}

	maxval++;

	vector<int> bkt[i];
	for(int i=0;i<n;i++)
	{
		int bi=(k*arr[i])/maxval;
		bkt[bi].push_back(arr[i]);
	}

	for(int i=0;i<k;i++)
		sort(bkt[i].begin(),bkt[i].end());

	int index=0;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<bkt[i].size();j++)
			arr[index++]=bkt[i][j];
	}
}

int main()
{
	int arr[]={30,40,10,80,5,12,70};
	int n=sizeof(arr)/sizeof(int);
	int k=4;

	bucketSort(arr,n,k);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}