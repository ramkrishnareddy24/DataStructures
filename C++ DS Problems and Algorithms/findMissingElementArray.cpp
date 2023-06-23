#include<bits/stdc++.h>
using namespace std;

int findMissing(int arr[],int n)
{
	int totalSum=(n*(n+1))/2;

	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];

	return totalSum-sum;
}

int main()
{
	int arr[]={0,1,2,3,4,5,6,7,8,10,11};
	int n=sizeof(arr)/sizeof(int);
	cout<<"findMissing :"<<findMissing(arr,n);
}