#include<bits/stdc++.h>
using namespace std;

//Recursive 
int fun(int ind,vector<int>& heights){
	if(ind==0) return 0;

	int left = fun(ind-1,heights)+abs(heights[ind]-heights[ind-1]);
	int right = INT_MAX;
	if(ind>1)
		right = fun(ind-2,heights)+abs(heights[ind]-heights[ind-2]);
	return min(left,right);

}

int frogJump(int n,vector<int>& heights){
	return fun(n-1,heights);
}

//Memoization
int fun(int ind,vector<int>& heights,vector<int>& dp){
	if(ind==0) return 0;

	if(dp[ind]!=-1) return dp[ind];

	int left = fun(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
	int right = INT_MAX;
	if(ind>1)
		right = fun(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
	
	return dp[ind] = min(left,right);

}

int frogJump(int n,vector<int>& heights){
	vector<int> dp(n+1,-1);
	return fun(n-1,heights,dp);
}

//Tabulation
int frogJump(int n,vector<int>& heights){

	vector<int> dp(n+1,0);
	
	for(int i=1;i<n;i++){
		int fs = dp[i-1]+abs(heights[i]+heights[i-1]);
		int ss = INT_MAX;
		if(i>1)
			int ss = dp[i-2]+abs(heights[i]-heights[i-2]);

		dp[i] = min(fs,ss);
	}
	return dp[n-1];
	
}

//Leetcode Modified
int maxJump(vector<int>& heights){
	int n = heights.size();
	int res = heights[1];

	for(int i=2;i<n;i++){
		res = max(res,heights[i]-heights[i-2]);
	}
	return res;
}

int main(){
	vector<int> heights = {30,10,60,10,60};
	int n = sizeof(heights)/sizeof(heights[0]);
	int ans = frogJump(n,heights);
	cout<<ans;
	
	return 0;
}

