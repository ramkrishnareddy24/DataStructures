#include<bits/stdc++.h>
using namespace std;

//Fibonacci Recursion :O(2^n)
int fib(int n)
{
	if(n==0 || n==1)
		return n;
	else
		return fib(n-1)+fib(n-2);
}

// Memorization Solution of Fibonacci : Theta(n)
int Fibo(int n)
{
	int memo[n+1];
	memset(memo,-1,sizeof(memo));
	if(memo[n]==-1)
	{
		int res=0;
		if(n==0 || n==1)
			res=n;
		else
			res=Fibo(n-1)+Fibo(n-2);
		memo[n]=res;
	}
	return memo[n];
}

// Tabulation Solution of Fibonacci
int Fibonacci(int n)
{
	int f[n+1];
	f[0]=0;
	f[1]=1;

	for(int i=2;i<=n;i++)
		f[i]=f[i-1]+f[i-2];

	return f[n];
}

// Longest Common Subsequence :O(2^n) 
int lcs(string s1,string s2,int m,int n)
{
	if(m==0 || n==0)
		return 0;

	if(s1[m-1]==s2[n-1])
		return 1+lcs(s1,s2,m-1,n-1);
	else
		return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
}

// Longest Common Subsequence (Memorization Solution) :theta(mn)
int lcsMemorization(string s1,string s2,int m,int n)
{
	int memo[m+1][n+1];
	memset(memo,-1,sizeof(memo));

	if(memo[m][n]!=-1)
		return memo[m][n];

	if(m==0 || n==0)
		memo[m][n]=0;
	else
	{
		if(s1[m-1]==s2[n-1])
			return 1+lcsMemorization(s1,s2,m-1,n-1);
		else
			memo[m][n] = max(lcsMemorization(s1,s2,m-1,n),lcsMemorization(s1,s2,m,n-1));
	}

	return memo[m][n];
}

// Longest Common Subsequence (Tabulation) :theta(mn)
int lcsTabulation(string s1,string s2)
{
	int m=s1.length(),n=s2.length();
	int dp[m+1][n+1];

	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int j=0;j<=n;j++)
		dp[0][j]=0;

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(s1[i-1]==s2[j-1])
				dp[i][j] = 1+dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);

	return dp[m][n];
}

// Coin Change
int getCount(int coins[],int n,int sum)
{
	if(sum==0)
		return 1;
	if(n==0)
		return 0;

	int res=getCount(coins,n-1,sum);
	if(coins[n-1]<=sum)
		res+=getCount(coins,n,sum-coins[n-1]);

	return res;
}

// coin Change DP Solution (Tabulation)
int GetCount(int coins[],int n,int sum)
{
	int dp[sum+1][n+1];
	for(int i=0;i<=n;i++)
		dp[0][i]=1;
	for(int i=1;i<=sum;i++)
		dp[i][0]=0;

	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(coins[j-1]<=i)
				dp[i][j]+=dp[i-coins[j-1]][i];
		}
	}

	return dp[sum][n];
}

int main()
{
	int n = 5;
	int n1 = fib(n);
	cout<<"The "<<n<<" Fibonacci Number is :"<<n1<<endl;
	cout<<"The Fibonacci(Memorization) is :"<<Fibo(5)<<endl; 
	cout<<"The Fibonacci(Tabulation) :"<<Fibonacci(5)<<endl;

	string s1="AXYZ";
	string s2="BAZ";

	cout<<"Longest Common Subsequence :"<<lcs(s1,s2,s1.length(),s2.length())<<endl;

	cout<<"Longest Common Subsequence(Memorization) :"<<lcsMemorization(s1,s2,s1.length(),s2.length())<<endl;

	cout<<"LCS (Tabulation) :"<<lcsTabulation(s1,s2)<<endl;

	int arr[3]={1,2,3};
	cout<<"Coin Change :"<<getCount(arr,3,4)<<endl;
	cout<<"Coin change (Tabulation) :"<<GetCount(arr,3,4)<<endl;

}