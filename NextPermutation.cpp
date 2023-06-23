#include<bits/stdc++.h>
using namespace std;

void NextPermutation(vector<int>& nums)
{
	int n=nums.size(),k,l;

	for(k=n-2;k>=0;k--)
	{
		if(nums[k]<nums[k+1])
			break;
	}

	if(k<0)
		reverse(nums.begin(),nums.end());
	else
	{
		for(l=n-1;l>k;l--)
			if(nums[k]<nums[l])
				break;

		swap(nums[k],nums[l]);
		reverse(nums.begin()+k+1,nums.end());
	}
}

void nextPermutation(vector<int>& v)
{
	next_permutation(v.begin(),v.end());	
}

int main()
{
	vector<int> v={1,2,3};
	// NextPermutation(v);
	nextPermutation(v);
	for(auto x:v)
		cout<<x<<" ";

	return 0;
}