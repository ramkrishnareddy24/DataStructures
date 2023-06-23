					//...Kadane Algorithm...//
#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int maxSubArraySum(int arr[],int n)
{
	int res=arr[0];
	for(int i=0;i<n;i++)
	{
		int curr=0;
		for(int j=i;j<n;j++)
		{
			curr=curr+arr[j];
			res=max(res,curr);
		}
	}
	return res;
}

//Efficient Solution
//Kandane's Algorithm
int MaxSubArraySum(int arr[],int n)
{
	int res=arr[0];
	int maxEnding=arr[0];
	for(int i=1;i<n;i++)
	{
		maxEnding=max(maxEnding+arr[i],arr[i]);
		res=max(res,maxEnding);
	}
	return res;
}

int main()
{
	int arr[]={3,-4,5,0,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<" "<<maxSubArraySum(arr,n);
	cout<<" "<<MaxSubArraySum(arr,n);
	return 0;
}