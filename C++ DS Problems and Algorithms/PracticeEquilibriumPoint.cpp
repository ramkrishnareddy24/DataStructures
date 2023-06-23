#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
//Equilibrium Index of an array
int equilibriumPoint(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];

	int l_sum=0;
	for(int i=0;i<n;i++)
	{
		if(l_sum==sum-arr[i])
			return i;

		l_sum+=arr[i];
		sum-=arr[i];
	}
	return -1;
}

int main()
{
	int arr[]={3,4,8,-9,20,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<equilibriumPoint(arr,n);
	return 0;
}