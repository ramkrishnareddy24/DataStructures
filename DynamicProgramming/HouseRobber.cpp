#include<bits/stdc++.h>
using namespace std;

//Optimal Solution
int maxAdjSum(vector<int>& nums){
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

long long int houseRobber(vector<int>& valueInHouse){
	int n = valueInHouse.size();

	vector<int> temp1,temp2;

	for(int i=0;i<n;i++){
		if(i!=0) temp1.push_back(valueInHouse[i]);
		if(i!=n-1) temp2.push_back(valueInHouse[i]);
	}
	return max(maxAdjSum(temp1),maxAdjSum(temp2));
}

int main()
{

}