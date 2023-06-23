#include<bits/stdc++.h>
using namespace std;

//Naive Solution  O(n^2)
int equilibriumPoint(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int l_sum=0;
		for(int j=0;j<i;j++)
			l_sum+=arr[j];

		int r_sum=0;
		for(int k=i+1;k<n;k++)
			r_sum+=arr[k];

		if(l_sum==r_sum)
			return i;		//returns the equilibrium index
	}
	return -1;
}


//Efficient Solution O(n)
bool EquilibriumPoint(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];

	int l_sum=0;
	for(int i=0;i<n;i++)
	{
		if(l_sum==sum-arr[i])
			return true;

		l_sum+=arr[i];
		sum-=arr[i];
	}
	return false;
}

int main()
{
	int arr[]={3,4,8,-9,20,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<equilibriumPoint(arr,n)<<endl;
	cout<<EquilibriumPoint(arr,n);
	return 0;
}