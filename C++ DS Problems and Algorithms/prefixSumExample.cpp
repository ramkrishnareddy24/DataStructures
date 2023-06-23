#include<bits/stdc++.h>
using namespace std;

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
	return false;
}

int commonSum(int arr[],int pos)
{
	int sum=0;
	for(int i=0;i<pos;i++)
		sum+=arr[i];
	return sum;
}

int main()
{
	int arr[]={4,6,9,6,4};
	int n=sizeof(arr)/sizeof(arr[0]);

	int findPos=equilibriumPoint(arr,n);
	cout<<arr[findPos]<<" "<<commonSum(arr,findPos);
}