#include<bits/stdc++.h>
using namespace std;

void prefixSumArray(int arr[],int n)
{
	int prefix[n];
	prefix[0]=arr[0];
	for(int i=1;i<n;i++)
		prefix[i]=arr[i]+prefix[i-1];

	for(int i=0;i<n;i++)
		cout<<prefix[i]<<" ";
}

int prefixSum(int prefix[],int l,int r)
{
	if(l!=0)
		return prefix[r]-prefix[l-1];
	else
		return prefix[r];
}

int main()
{
	int arr[]={2,8,3,9,6,5,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	int l=0;
	int r=n-1;
	prefixSumArray(arr,n);
	cout<<endl<<prefixSum(arr,2,4);
	return 0;
}