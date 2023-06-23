#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
int maxSubArraySum(int arr[],int n)
{
	int maxEnding=arr[0];
	int res=arr[0];
	for(int i=1;i<n;i++)
	{
		maxEnding=max(maxEnding+arr[i],arr[i]);
		res=max(res,maxEnding);
	}
	return res;
}

int maxCircularSubArraySum(int arr[],int n)
{
	int maxNormal=maxSubArraySum(arr,n);

	if(maxNormal<0)
		return maxNormal;

	int arr_sum=0;
	for(int i=0;i<n;i++)
	{
		arr_sum+=arr[i];
		arr[i]=-arr[i];
	}
	int maxCircular=arr_sum+maxSubArraySum(arr,n);
	return max(maxNormal,maxCircular);
}

int main()
{
	int arr[]={8,-8,9,-9,10,-11,12};
	int n=sizeof(arr)/sizeof(int);
	cout<<maxCircularSubArraySum(arr,n);
	return 0;
}