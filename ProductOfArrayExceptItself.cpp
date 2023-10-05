#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
	vector<int> ans;
	int product = 0;

	for(int i=0;i<nums.size();i++)
		product = product*nums[i];

	cout<<product;

	for(int i=0;i<nums.size();i++){
		ans.push_back(product/nums[i]);
	}

	return ans;
}

int main()
{
	vector<int> nums = {1,2,3,4};
	vector<int> ans = productExceptSelf(nums);
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}