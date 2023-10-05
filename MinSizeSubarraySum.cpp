#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target,vector<int>& nums)
{
	int window = INT_MAX;
	int start = 0,end = 0;
	int currSum = 0;

	for(int endd=0;end<nums.size();end++)
	{
		currSum+=nums[end];

		while(currSum>=target)
		{
			window = min(window,end-start+1);
			currSum-=nums[start];
			start++;
		}
	}

	return window == INT_MAX ? 0 : window;
}

int main()
{
	vector<int> nums = {2,3,1,2,4,3};
	int target = 7;
	int window = minSubArrayLen(target,nums);
	cout<<window;

	return 0;
}