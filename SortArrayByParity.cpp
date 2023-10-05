#include<bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums)
{
	int n = nums.size();
	int left = 0;
	int right = n-1;

	int i=0;

	while(left<right){
		while(left<right && nums[left]%2==0) left++;
		while(left<right && nums[right]%2!=0) right--;
		swap(nums[left],nums[right]);
	}
	
	return nums;
}

int main()
{
	vector<int> nums = {3,1,2,4};
	vector<int> ans = sortArrayByParity(nums);
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}