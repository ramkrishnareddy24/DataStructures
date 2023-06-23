#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> nums)
{
	if(nums.size()==0)
		return 0;
	
	sort(nums.begin(),nums.end());
	
	int res=1;
	int prev=nums[0];
	int count=1;

	for(int i=1;i<nums.size();i++)
	{
		if(nums[i]==prev+1)
			count++;
		else if(nums[i]!=prev)
			count=1;

		prev=nums[i];
		res=max(res,count);
	} 
	return res;
}

int main()
{
	vector<int> v={1,2,0,1};
	int res=longestConsecutive(v);
	cout<<res;
	return 0;
}