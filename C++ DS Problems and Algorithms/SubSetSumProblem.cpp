#include<bits/stdc++.h>
using namespace std;

int subSetSum(int arr[],int n,int sum)
{
	if(n==0)
		return (sum==0)?1:0;
	else
		return subSetSum(arr,n-1,sum)+subSetSum(arr,n-1,sum-arr[n-1]);
}

int main()
{
	int arr[]={1,1,2,2,3,4,5,5,6,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<subSetSum(arr,n,1);
	return 0;
}