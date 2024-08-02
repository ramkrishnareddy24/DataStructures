#include<bits/stdc++.h>
using namespace std;

//Recursion
int solveUtil(int ind,vector<int>& nums){
	if(ind==0) return nums[ind];
	if(ind<0) return 0;

	int pick = nums[ind] + solveUtil(ind-2,nums);
	int notPick = 0 + solveUtil(ind,nums);

	return max(pick,notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
	int n = nums.size();
	return solveUtil(n-1,nums);
}

//Memoization
int solveUtil(int ind,vector<int>& nums,vector<int>& dp){
	if(ind==0) return nums[ind];
	if(ind<0) return 0;

	if(dp[ind]!=-1) return nums[ind];

	int pick = nums[ind] + solveUtil(ind-2,nums);
	int notPick = 0 + solveUtil(ind);

	return dp[ind] = max(pick,notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
	int n = nums.size();
	vector<int> dp(n,-1);
	return solveUtil(n-1,nums,dp);
}

//Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
	int n = nums.size();
	vector<int> dp(n,0);

	dp[0] = nums[0];
	int neg = 0;

	for(int i=1;i<n;i++){
		int take = dp[i];
		if(i>1) take += dp[i-2];
		int notTake = 0 + dp[i-1];

		dp[i] = max(take,notTake);
	}
	return dp[n-1];
}

int main()
{

}