#include<bits/stdc++.h>
using namespace std;

// Fibonacci | Memoization
int fib(int n)
{
	int dp[n+1];
	memset(dp,-1,sizeof(dp));

	if(n<=1) return n;
	if(dp[n]!=-1) return dp[n];
	return dp[n]=fib(n-1)+fib(n-2);
}

// Fibonacci | Tabulation
int fibo(int n)
{
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	dp[1]=1;

	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}

	return dp[n];
}

// Optimal Solution for Fibonacci
int fibonacci(int n)
{
	int prev_prev=0;
	int prev=1;
	int res=0;

	for(int i=2;i<=n;i++)
	{
		res = prev_prev+prev;
		prev_prev=prev;
		prev=res;
	}
	return res;
}

// Climbing stairs Variation of Fibonaaci | Recursion
int climbStairs(int stairs)
{
	if(stairs==0 || stairs==1)
		return 1;

	int left = climbStairs(stairs-1);
	int right = climbStairs(stairs-2);

	return left+right;
}

// Climbing stairs Variation of Fibonaaci | Memoization
int climbStairsMem(int n)
{
	int dp[n+1];
	memset(dp,-1,sizeof dp);

	if(n == 0 || n == 1)
		return 1;

	if(dp[n]!=-1)
		return dp[n] = climbStairsMem(n-1)+climbStairsMem(n-2);
}

// Frog Jump | Recursion
int jump(int n,vector<int>& arr)
{
	if(n==0) return 0;
	int right=INT_MAX;

	int left = jump(n-1,arr)+abs(arr[n]-arr[n-1]);
	if(n>1)
		right = jump(n-2,arr)+abs(arr[n]-arr[n-2]);

	return min(left,right);
}

// Frog Jump | Memoization
int Jumps(int n,vector<int>& arr)
{	
	if(n==0) return 0;

	int dp[n+1];
	memset(dp,-1,sizeof dp);

	if(dp[n]!=-1)
		return  dp[n];

	int left = Jumps(n-1,arr)+abs(arr[n]-arr[n-1]);

	int right=1e9;
	if(n>1) 
		right = Jumps(n-2,arr)+abs(arr[n]-arr[n-2]);

	return dp[n] = min(left,right);
}

// Frog Jumps | Tabulation
int FrogJumps(int n,vector<int>& heights)
{
	vector<int> dp(n,0);
	dp[0]=0;

	for(int i=1;i<n;i++)
	{
		int fs = dp[i-1]+abs(heights[i]-heights[i-1]);
		int ss = INT_MAX;
		if(i>1)
			ss = dp[i-2]+abs(heights[i]-heights[i-2]);

		dp[i] = min(fs,ss);
	}
	return dp[n-1];
}

// Frog Jump :K Jumps | Recursion
int kjump(int n,int k,vector<int>& arr)
{
	if(n==0) return 0;

	int mmJump=INT_MAX;

	for(int i=1;i<=k;i++)
	{
		if(n-i>=0)
		{
			int jump=kjump(n-i,k,arr)+abs(arr[n]-arr[n-i]);
			mmJump=min(mmJump,jump);
		}
	}
	return mmJump;
}

// Frog Jump :K Jumps | Memoization
int Kjumps(int n,int k,vector<int>& arr)
{
	if(n==0) return 0;

	int dp[n+1];
	memset(dp,-1,sizeof dp);

	int mmJump=1e9;

	if(dp[n]!=-1)
		return dp[n];

	for(int i=1;i<=k;i++)
	{
		if(n-i>=0)
		{
			int jump=Kjumps(n-i,k,arr)+abs(arr[n]-arr[n-i]);
			mmJump=min(mmJump,jump);
		}		
	}
	
	return dp[n]=mmJump;
}

// Frog Jump :K Jumps | Tabulation
int KjumpS(int n,int k,vector<int>& arr)
{
	int dp[n+1];
	dp[0]=0;

	for(int i=1;i<n;i++)
	{
		int mmJump=1e9;
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
			{
				int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
				mmJump=min(jump,mmJump);
			}
		}
		dp[i]=mmJump;
	}
	return dp[n-1];
}

// Maximum sum of Non-adjacent elements | House Robber | Recursion
int maxSum(int n,vector<int>& arr)
{
	if(n==0) return arr[n];
	if(n<0) return 0;

	int pick = arr[n]+maxSum(n-2,arr);
	int notPick = 0+maxSum(n-1,arr);

	return max(pick,notPick);
}

// Maximum sum of Non-adjacent elements | House Robber | Memoization
int MaxSum(int n,vector<int>& arr)
{
	if(n==0) return arr[n];
	if(n<0) return 0;

	vector<int> dp(n+1,-1);
	if(dp[n]!=-1)
		return dp[n];

	int pick = arr[n]+MaxSum(n-2,arr);
	int notPick = 0+MaxSum(n-1,arr);

	return dp[n]=max(pick,notPick);
}

// Maximum sum of Non-adjacent elements | House Robber | Tabulation
int MAXsum(int n,vector<int>& arr)
{
	if(n<0) return 0;

	vector<int> dp(n+1,0);
	dp[0]=arr[0];

	for(int i=1;i<=n;i++)
	{
		int take = arr[i];
		if(i>1)
			take += dp[i-2];
		int nonTake = 0+dp[i-1];

		dp[i] = max(take,nonTake);
	}

	return dp[n-1];
}

// Maximum sum of Non-adjacent elements | House Robber-2 (circular Array) | Tabulation
int houseRobber(int n,vector<int>& arr)
{
	vector<int> temp1,temp2;
	if(n==1) return arr[0];
	for(int i=0;i<n;i++)
	{
		if(i != 0) temp1.push_back(arr[i]);
		if(i != n-1) temp2.push_back(arr[i]);
	}

	return max(MAXsum(temp1.size(),temp1),MAXsum(temp2.size(),temp2));
}

int main()
{
	cout<<"Fibo using Memoization :"<<fib(3)<<endl;
	cout<<"Fibo using Tabulation :"<<fibo(3)<<endl;
	cout<<"Fibo Optimal :"<<fibonacci(6)<<endl;
	cout<<"Climb Stairs :"<<climbStairs(3)<<endl; 

	vector<int> v = {2,3,1,1,4};
	cout<<"Frog Jump (Recursion) :"<<jump(v.size()-1,v)<<endl;
	cout<<"Frog Jump (Memoization) :"<<Jumps(v.size()-1,v)<<endl;
	cout<<"Frog Jump (Tabulation) :"<<FrogJumps(v.size()-1,v)<<endl;

	cout<<"Frog K Jumps Recursion :"<<kjump(v.size()-1,3,v)<<endl;
	cout<<"Frog K Jumps Memoization :"<<Kjumps(v.size()-1,3,v)<<endl;
	cout<<"Frog K Jumps Tabulation :"<<KjumpS(v.size()-1,3,v)<<endl;

	vector<int> v1 = {2,7,9,3,1};
	cout<<"Maximum sum of Non-adjacent elements R :"<<maxSum(v1.size()-1,v1)<<endl;
	cout<<"Maximum sum of Non-adjacent elements M :"<<MaxSum(v1.size()-1,v1)<<endl;
	cout<<"Maximum sum of Non-adjacent elements T :"<<MAXsum(v1.size(),v1)<<endl;

	vector<int> v3 = {2,3,2};
	cout<<"House houseRobber :"<<houseRobber(v3.size()-1,v3)<<endl;
	

}