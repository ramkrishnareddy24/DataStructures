#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums){
	int index = nums.size()-1;
	int n = nums.size();

	for(int i=n-1;i>=0;i--){
		if(nums[i]+i>=index)
			index=i;
	}
	
	if(index==0)
		return true;
	else
		return false;
}

int main()
{
	vector<int> nums = {2,3,1,1,4};
	bool ans = canJump(nums);
	cout<<ans;

	return 0;
}