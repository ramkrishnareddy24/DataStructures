#include<bits/stdc++.h>
using namespace std;

// O(n)
vector<int> productExceptSelf(vector<int>& nums)
{
	int n = nums.size();
	vector<int> left;
	vector<int> right;
	vector<int> output;

	if(n<2) return nums;

	left[0] = nums[0];
	for(int i=1;i<n;i++){
		left[i] = left[i-1]*nums[i]; 
	}

	right[n-1] = nums[n-1];
	for(int i=n-2;i>=0;i--){
		right[i] = right[i+1]*nums[i];
	}

	output[0] = right[1];
	for(int i=1;i<n;i++){
		output[i] = left[i-1]*right[i+1];
	}

	return output;	
}

vector<int> ProductExceptSelf(vector<int>& nums)
{
	int n = nums.size();
	vector<int> output;

	if(n<1) return output;

	int product = 1;
	for(int i=0;i<n;i++){
		product = product*nums[i];
		output.push_back(product);
	}

	product = 1;
	for(int i=n-1;i>0;i--){
		output[i] = output[i-1]*product;
		product = product*nums[i];
	}
	output[0] = product;

	return output;
}

int main()
{
	vector<int> nums = {1,2,3,4};
	vector<int> ans = ProductExceptSelf(nums);
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}