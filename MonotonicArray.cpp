#include<bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int>& nums)
{
	int n = nums.size();

	for(int i=1;i<n-1;i++)
	{
		if(!((nums[i]>=nums[i-1] && nums[i]<=nums[i+1] && (nums[0]<=nums[n-1]) && (nums[i]<=nums[n-1])) || (nums[i]<=nums[i-1] && nums[i]>=nums[i+1]) && (nums[n-1]<=nums[0]) && ((nums[i]>=nums[n-1]))))
			return false;
	}
	return true;
}

int main()
{
	vector<int> arr = {1,2,3,3,3,3,3,3,5,5,5,5,2,2,2,1,1,1};
	bool ans = isMonotonic(arr);
	cout<<ans;

	return 0;
}