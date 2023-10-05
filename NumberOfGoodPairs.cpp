#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums)
{
	int n = nums.size();
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(nums[i]==nums[j] && i<j)
				count++;
		}
	}
	return count;
}

int main()
{
	vector<int> nums = {1,1,1,1};
	int goodPairs = numIdenticalPairs(nums);
	cout<<goodPairs;

	return 0;
}