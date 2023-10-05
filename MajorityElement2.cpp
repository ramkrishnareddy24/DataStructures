#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
	int n = nums.size();
	unordered_map<int,int> mp;
	vector<int> ans;

	for(auto it:nums)
		mp[it]++;

	for(auto it:mp)
		if(it.second>n/3)
			ans.push_back(it.first);
	sort(ans.begin(),ans.end());
	return ans;
}

int main()
{
	vector<int> nums = {1,2};
	vector<int> majority = majorityElement(nums);
	for(auto it:majority)
		cout<<it;
	return 0;
}