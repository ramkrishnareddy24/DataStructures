#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums)
{
	int n=nums.size();
	int res=nums[0];
	int maxEnding=nums[0];

	for(int i=1;i<n;i++)
	{
		maxEnding=max(maxEnding+nums[i],nums[i]);
		res=max(res,maxEnding);
	}
	return res;
}

int main()
{
	vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
	int res = maxSubArray(v);
	cout<<res;
	return 0;
}