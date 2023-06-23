#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int maxDifference(int arr[],int n)
{
	int res=arr[1]-arr[0];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n-1;j++)
			res=max(res,arr[j]-arr[i]);
	}
	return res;
}

//Efficient Solution
int MaxDifference(int arr[],int n)
{
	int res=arr[1]-arr[0];
	int minVal=arr[0];
	for(int j=1;j<n;j++)
	{
		res=max(res,arr[j]-minVal);
		minVal=min(minVal,arr[j]);
	}
	return res;
}

int main()
{
	int arr[]={2,3,10,6,8,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<maxDifference(arr,n);
	cout<<"\t"<<MaxDifference(arr,n);

	return 0;
}