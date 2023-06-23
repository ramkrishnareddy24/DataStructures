#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int maxDifference(int arr[],int n)
{
	int res=arr[1]-arr[0];
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			res=max(res,arr[j]-arr[i]);
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
	int arr[]={2, 4, 8, 7, 7, 9, 3};
	int n=sizeof(arr)/sizeof(int);
	cout<<maxDifference(arr,n);
	cout<<"\t"<<MaxDifference(arr,n);

	return 0;
}