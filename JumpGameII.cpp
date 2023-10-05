#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
	int jumps = 0;
	int farthest = 0;
	int current = 0;

	for(int i=0;i<nums.size()-1;i++){
		farthest = max(farthest,nums[i]+i);

		if(i==current){
			current = farthest;
			jumps++;
		}
	}
	return jumps;        
}

int main()
{
	vector<int> nums = {2,3,1,1,4};
	int ans = jump(nums);
	cout<<ans;

	return 0;
}