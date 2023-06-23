#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
int minDifference(int arr[],int n,int m)
{
	if(m>n)
		return -1;
	sort(arr,arr+n);

	int res=arr[m-1]-arr[0];
	for(int i=0;(i+m-1)<n;i++)
		res=min(res,(arr[i+m-1]-arr[i]));
	return res;
}

int main()
{
	int arr[]={1,1,2,2,3,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<minDifference(arr,n,3);
	return 0;
}