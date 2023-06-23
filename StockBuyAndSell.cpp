#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &nums)
{
	int n=nums.size();
	int maxPro=0;

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(nums[j]>nums[i])
				maxPro=max(maxPro,nums[j]-nums[i]);

	return maxPro;
}

int MaxProfit(vector<int>& nums)
{
	int n=nums.size();
	int maxPro=0;
	int minPrice=INT_MAX;

	for(int i=0;i<n;i++)
	{
		minPrice=min(minPrice,nums[i]);
		maxPro=max(maxPro,nums[i]-minPrice);
	}
	return maxPro;
}

int main()
{
	vector<int> nums={7,1,5,3,6,4};
	int maxPro=maxProfit(nums);
	cout<<maxPro<<" "<<MaxProfit(nums)<<endl;

	return 0;
}