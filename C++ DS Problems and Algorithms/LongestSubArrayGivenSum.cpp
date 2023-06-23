#include<iostream>
#include<unordered_map>
using namespace std;

//Naive Solution
int longestSubArray(int arr[],int n,int sum)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		int curr_sum=0;
		for(int j=i;j<n;j++)
		{
			curr_sum+=arr[j];
			if(curr_sum==sum)
			{
				res=max(res,j-i+1);
			}
		}
	}
	return res;
}

//Efficient Solution
int LongestSubArray(int arr[],int n,int sum)
{
	unordered_map<int,int> m;
	int res=0;
	int pref_sum=0;
	for(int i=0;i<n;i++)
	{
		pref_sum+=arr[i];

		if(pref_sum==sum)
			res=i+1;
		if(m.find(pref_sum)==m.end())
			m.insert({pref_sum,i});
		if(m.find(pref_sum-sum)!=m.end())
			res=max(res,i-m[pref_sum-sum]);
	}
	return res;
}


int main()
{
	int arr[]={5,8,-4,-4,9,-2,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	// int sum=4;
	cout<<longestSubArray(arr,n,0)<<" ";
	cout<<LongestSubArray(arr,n,0);
	return 0;
}