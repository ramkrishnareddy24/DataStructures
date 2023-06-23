#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int maxCircularSubArraySum(int arr[],int n)
{
	
	int res=arr[0];
	for(int i=0;i<n;i++)
	{
		int curr_max=arr[i];
		int curr_sum=arr[i];
		for(int j=1;j<n;j++)
		{
			int index=(i+j)%n;
			curr_sum+=arr[index];
			curr_max=max(curr_sum,curr_max);
		}
		res=max(res,curr_max);
	}
	return res;
}

//Efficcient Solution
int maxSubArraySum(int arr[],int n) //Kadane's Algo
{
	int res=arr[0];
	int maxEnding=arr[0];
	for(int i=1;i<n;i++)
	{
		maxEnding=max(maxEnding+arr[i],arr[i]);
		res=max(maxEnding,res);
	}
	return res;
}

int MaxCircularSubArraySum(int arr[],int n)
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
	int arr[]={8, -8, 9, -9, 10, -11, 12};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"maxSubArraySum :"<<maxSubArraySum(arr,n);
	cout<<" "<<maxCircularSubArraySum(arr,n);
	cout<<" "<<MaxCircularSubArraySum(arr,n);

	return 0;
}