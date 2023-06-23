#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int BucketSort(int arr[],int n,int k)
{
	int max=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	max++;

	vector<int> bkt[k];
	for(int i=0;i<n;i++)
	{
		int bi=(k*arr[i])/max;
		bkt[bi].push_back(arr[i]);
	}

	for(int i=0;i<k;i++)
		sort(bkt[i].begin(),bkt[i].end());

	int index=0;
	for(int i=0;i<k;i++)
		for(int j=0;j<bkt[i].size();j++){
			arr[index++]=bkt[i][j];
		}

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int arr[]={77,65,45,54,33,21,22,20,80,11};
	int n=sizeof(arr)/sizeof(int);
	int k=4;

	BucketSort(arr,n,k);

}