#include<bits/stdc++.h>
using namespace std;

int longestSubArray(int arr[],int n)
{
	unordered_map<int,int> mpp;
	int maxi=0;
	int sum=0;

	for(int i=0;i<n;i++)
	{
		sum+=arr[i];

		if(sum==0)
		{
			maxi=i+1;
		}
		else
		{
			if(mpp.find(sum)!=mpp.end())
			{
				maxi=max(maxi,i-mpp[sum]);
			}
			else
			{
				mpp[sum]=i;	
			}
		}
	}
	return maxi;
}

int main()
{
	int arr[]={9, -3, 3, -1, 6, -5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int res=longestSubArray(arr,n);
	cout<<res;
	return 0;
}