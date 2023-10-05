#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> nums,int target)
{
	int n = nums.size();
	int lo = 0;
	int hi = n-1;
	vector<int> indexes;

	while(lo<hi)
	{
		if(nums[lo]+nums[hi]>target)
			hi--;
		else if(nums[lo]+nums[hi]<target)
			lo++;
        else if(nums[lo]+nums[hi]==target)
        break;
	}
    indexes.push_back(lo+1);
    indexes.push_back(hi+1);
	return indexes;
}

int main()
{
	vector<int> nums = {2,7,11,15};
	int target = 9;
	vector<int> indexes = twoSum(nums,target);
	for(auto it:indexes)
		cout<<it;
	return 0;
}