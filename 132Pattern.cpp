#include<bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int>& nums)
{
	int n = nums.size();
	vector<int> minarr(n);

	minarr[0] = nums[0];
	for(int i=1;i<n;i++)
		minarr[i] = min(minarr[i],nums[i-1]);

	stack<int> st;
	for(int j=n-1;j>=0;j--){
		while(!st.empty() && st.top()<=minarr[j]) st.pop();
		if(!st.empty() && st.top()<nums[j])
			return true;
		st.push(nums[j]);
	}
	return false;
}

int main()
{
	vector<int> nums = {3,1,4,2};
	bool ans = find132pattern(nums);
	cout<<ans;
	return 0;
}