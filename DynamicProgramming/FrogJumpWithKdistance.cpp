#include<bits/stdc++.h>
using namespace std;

//Memoization
int solveUtil(int ind,vector<int>& heights,vector<int>& dp,int k){
	if(ind==0) return 0;

	if(dp[ind]!=-1) return dp[ind];

	int mmSteps = INT_MAX;
	for(int j=1;j<=k;j++){
		if(ind-j>=0){
			int jump = solveUtil(ind-j,heights,dp,k)+abs(heights[ind]-heights[ind-j]);
			mmSteps = min(jump,mmSteps);
		}
	}
	return dp[ind] = mmSteps;
}

int frogJumpK(int n,vector<int>& heights,int k){
	vector<int> dp(n,-1);
	return solveUtil(n-1,heights,dp,k);
}

//Tabulation
int solveUtil(int ind,vector<int>& heights,vector<int>& dp,int k){
	dp[0] = 0;

	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				int jump = dp[i-j]+abs(heights[i]+heights[i-j]);
				mmSteps = min(jump,mmSteps);
			}
		}
		dp[i] = mmSteps;
	}
	dp[n-1];
}

int frogJumpK(int n,vector<int>& heights,int k){
	vector<int> dp(n,-1);
	return solveUtil(n-1,heights,dp,k);
}

int main(){
	vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1); // Initialize a memoization array for the main function
    cout << solve(n, height, k) << endl; // Print the result of the solve function
    return 0;
}








