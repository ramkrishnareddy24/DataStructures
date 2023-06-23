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
	if(sum==0) return 1;

	if(n==0) return 0;

	int res=getCount(coins,n-1,sum);
	if(coins[n-1]<=sum)
		res=res+getCount(coins,n,sum-coins[n-1]);

	return res;
}


// coin Change DP Solution (Tabulation)
int GetCount(int coins[],int n,int sum)
{
	int dp[sum+1][n+1];

	for(int i=1;i<=sum;i++)
		dp[i][0]=0;
	for(int i=0;i<=n;i++)
		dp[0][i]=1;

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

// Edit Distance Recursive Solution
int editDistance(string s1,string s2,int m,int n)
{
	if(m==0) return n;
	if(n==0) return m;

	if(s1[m-1]==s2[n-1])
		return editDistance(s1,s2,m-1,n-1);
	else
		return 1+min(min(editDistance(s1,s2,m-1,n),editDistance(s1,s2,m,n-1)),editDistance(s1,s2,m-1,n-1));
}

// Edit Distance DP Solution (Tabulation) :theta(mn)
int editDistanceTabulation(string s1,string s2,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
		dp[i][0]=i;
	for(int j=0;j<=n;j++)
		dp[0][j]=j;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
		}
	}

	return dp[m][n];
}

// Longest Increasing Subsequence (Tabulation) :theta(n^2)
int LIS(int arr[],int n)
{
	int lis[n];
	lis[0]=1;

	for(int i=1;i<n;i++)
	{	lis[i]=1;
		for(int j=0;j<i;j++)
			if(arr[j]<arr[i])
				lis[j]=max(lis[i],lis[j]+1);
	}

	int res=lis[0];
	for(int i=1;i<n;i++)
		if(lis[i]>res)
			res=lis[i];
	return res;
}

// Longest Increasing Subsequence (Optimized: Binary Search) :O(nlogn)
int cielIdx(int arr[],int l,int r,int x)
{
	while(r>l)
	{
		int m=l+(r-1)/2;
		if(arr[m]>=x)
			r=m;
		else
			l=m+1;
	}
	return r;
}

int lis(int arr[],int n)
{
	int tail[n];
	int len=1;
	tail[0]=arr[0];

	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[len-1])
		{
			tail[len]=arr[i];
			len++;
		}
		else
		{
			int c=cielIdx(tail,0,len-1,arr[i]);
			tail[c]=arr[i];
		}
	}
	return len;
}

// Max Cuts Recursive Solution :O(3^n)
int maxCuts(int n,int a,int b,int c)
{
	if(n<0) return -1;
	if(n==0) return 0;

	int res=max({maxCuts(n-a,a,b,c),maxCuts(n-b,a,b,c),maxCuts(n-c,a,b,c)});

	if(res==-1)
		return res;
	else
		return res+1;
}

// maxCuts DP Solution (Tabulation) :theta(n) Aux: theta(n)
int maxCutsTabulation(int n,int a,int b,int c)
{
	int dp[n+1];
	dp[0]=0;

	for(int i=1;i<=n;i++)
	{
		dp[i]=-1;

		if(i-a>=0) dp[i] = max(dp[i-a],dp[i]);
		if(i-b>=0) dp[i] = max(dp[i-b],dp[i]);
		if(i-c>=0) dp[i] = max(dp[i-c],dp[i]);

		if(dp[i]!=-1)
			dp[i]++;
	}
	return dp[n];
}

// Minimum coins to make value | Recursive
int getMin(int coins[],int n,int val)
{
	if(val==0) return 0; 

	int res=INT_MAX;

	for(int i=0;i<n;i++)
	{
		if(coins[i]<=val){
			int subres = getMin(coins,n,val-coins[i]);

			if(subres!=INT_MAX)
				res = min(res,subres+1);
		}			
	}
	return res;
}

// Minimum coins to make value | DP Tabulation :theta(val*n)
int getMinTab(int coins[],int n,int val)
{
	int dp[val+1];
	dp[0]=0;

	for(int i=1;i<=val;i++)
		dp[i]=INT_MAX;

	for(int i=1;i<=val;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(coins[j]<=i){
				int subres=dp[i-coins[j]];
				if(subres!=INT_MAX)
					dp[i]=min(dp[i],subres+1);
			}
		}
	}
	return dp[val];
}

// Minimum Jumps to Reach End | Recursive
int minJumps(int arr[],int n)
{
	if(n==1) return 0;

	int res=INT_MAX;

	for(int i=0;i<=n-2;i++)
	{
		if(i+arr[i]>=n-1)
		{
			int subres=minJumps(arr,i+1);
			if(subres!=INT_MAX)
				res=min(res,subres+1);
		}
	}
	return res;
}

// Minimum Jumps to Reach End | DP Tabulation :theta(n^2)
int minJumpsTab(int arr[],int n)
{
	int dp[n];
	dp[0]=0;

	for(int i=1;i<n;i++)
		dp[i]=INT_MAX;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(j+arr[j]>=i)
			{
				if(dp[j]!=INT_MAX)
					dp[i]=min(dp[i],dp[j]+1);
			}
		}
	}
	return dp[n-1];
}

// 0-1 Knapsack Problem | Recursive :O(2^n)
int knapsack(int w,int wt[],int val[],int n)
{
	if(n==0 || w==0) return 0;

	if(wt[n-1]>w)
		return knapsack(w,wt,val,n-1);
	else
		return max(knapsack(w,wt,val,n-1),val[n-1]+knapsack(w-wt[n-1],wt,val,n-1));
}

// 0-1 Knapsack Problem | DP Solutin (Tabulation) :theta(nw)
int knapsackTab(int w,int wt[],int val[],int n)
{
	int dp[n+1][w+1];

	for(int i=0;i<=w;i++) dp[0][i]=0;
	for(int i=0;i<=n;i++) dp[i][0]=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(wt[i-1]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
		}
	}
	return dp[n][w];
}

// Optimal Strategy for Game | Recursive Solution 1
int Sol(int arr[],int i,int j,int sum)
{
	if(i+1==j)
		return max(arr[i],arr[j]);

	return max((sum-Sol(arr,i+1,j,sum-arr[i])),(sum-Sol(arr,i,j-1,sum-arr[j])));
}

int mainSol(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	return Sol(arr,0,n-1,sum);
}

// Optimal Strategy for Game | Recursive Solution 2
int Sol2(int arr[],int i,int j)
{
	if(i+1==j)
		return max(arr[i],arr[j]);
	return max(arr[i]+min(Sol2(arr,i+2,j),Sol2(arr,i+1,j-1)),arr[j]+min(Sol2(arr,i,j-2),Sol2(arr,i+1,j-1)));
}

// Optimal Strategy for Game | DP Tabulation :theta(n^2)
// int SolTab(int arr[],int n)
// {
// 	int dp[n][n];
// 	for(int i=0;i<n-1;i++)
// 		dp[i][i+1]=max(arr[i],arr[i+1]);

// 	for(int gap=3;gap<n;gap+=2)
// 	{
// 		for(int i=0;i+gap<n;i++)
// 		{
// 			j=i+gap;
// 			dp[i][j]=max(arr[i]+min(dp[i+1][j],dp[i+1][j-1]),arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
// 		}
// 	}
// 	return dp[0][n-1];
// }

// Maximum Sum Increasing Subsequence | DP Tabulation
int maxSumIncreSubseq(int arr[],int n)
{
	int msis[n];

	for(int i=0;i<n;i++)
	{
		msis[i]=arr[i];
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
				msis[i]=max(msis[i],msis[j]+arr[j]);
		}
	}

	int res=msis[0];
	for(int i=1;i<n;i++)
		if(msis[i]>res)
			res=msis[i];
	return res;
}

// Longest Bitonic Subsequence | DP Tabulation
int lbs(int arr[],int n)
{
	int lis[n];
	lis[0]=1;

	for(int i=1;i<n;i++)
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
				lis[i]=max(lis[i],lis[j]+1);
		}
	}

	int lds[n];
	for(int i=0;i<n;i++)
		lds[i]=1;

	for(int i=n-2;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[j]<arr[i])
				lds[i]=max(lds[i],lds[j]+1);
		}
	}

	int max=lis[0]+lds[0]-1;
	for(int i=1;i<n;i++)
		if(lis[i]+lds[i]-1>max)
			max=lis[i]+lds[i]-1;
	return max;
}

// Building Bridges | DP Tabulation
struct cityPairs
{
	int north,south;
};

bool compare(cityPairs a,cityPairs b)
{
	if(a.north==b.north)
		return a.south<b.south;
	return a.north<b.north;
}

int maxBridges(struct cityPairs values[],int n)
{
	int lis[n+1];
	for (int i=0;i<n;i++)
        lis[i]=1;

	sort(values,values+n,compare);

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;i++)
		{
			if(values[j].north<=values[i].north)
				lis[i]=max(lis[i],lis[j]+1);
		}
	}

	int max=lis[0];
	for(int i=1;i<n;i++)
		if(lis[i]>max)
			max=lis[i];
	return max;
}

// Egg Droping Problem | DP Tabulation :O(f^2 e^2)
int eggDrop(int f ,int e)
{
	int dp[f+1][e+1];
	for(int i=1;i<=e;i++)
	{
		dp[0][i]=0;
		dp[1][i]=1;
	}

	for(int i=1;i<=e;i++)
		dp[i][1]=i;

	for(int i=2;i<=f;i++)
	{
		for(int j=2;j<=e;j++)
		{
			dp[i][j]=INT_MAX;
			for(int x=1;x<=i;x++)
				dp[i][j]=min(dp[i][j],1+max(dp[i-1][j-1],dp[i-x][j]));
		}
	}

	return dp[f][e];
}

// Count number of BSTs possible | DP tabulation :O(n^2)
int countBSTs(int n)
{
	int dp[n+1];
	dp[0]=1;

	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		for(int j=0;j<i;j++)
		{
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}

	return dp[n];
}

// Maximum Sum with no consecutives | Recursive :O(2^n)
int maxSum(int arr[],int n)
{
	if(n==1)
		return arr[0];
	else if(n==2)
		return max(arr[0],arr[1]);
	else
		return max(maxSum(arr,n-1),maxSum(arr,n-2)+arr[n-1]);
}

// Maximum Sum with no consecutives | DP Tabulation :O(n)
int MaxSum(int arr[],int n)
{
	int dp[n];
	if(n==1)
		return arr[0];

	dp[1]=arr[0];
	dp[2]=max(dp[1],arr[1]);

	for(int i=3;i<=n;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+arr[i-1]);
	}

	return dp[n];
}

// Maximum Sum with no consecutives | DP Tabulation Space Optimized:O(n)
int MaxSumOptim(int arr[],int n)
{
	if(n==1) return arr[0];

	int prev_prev=arr[0];
	int prev=max(arr[0],arr[1]);

	int res=prev;
	for(int i=3;i<=n;i++)
	{
		res=max(prev,prev_prev+arr[i-1]);
		prev_prev=prev;
		prev=res;
	}
	return res;
}

// Subset Sum Problem | Recursive :theta(2^n)
int countSubsets(int arr[],int n,int sum)
{
	if(n==0)
		return (sum==0)? 1:0;
	return countSubsets(arr,n-1,sum)+countSubsets(arr,n-1,sum-arr[n-1]);
}

// Subset Sum Problem | DP 
int countSubsetsTab(int arr[],int n,int sum)
{
	int dp[n+1][sum+1]; 

	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int j=1;j<=sum;j++) dp[0][j]=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<arr[i-1])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
		}
	}
	return dp[n][sum];
}

// Matrix Chain Multiplication | Recursive
int matChain(int arr[],int i,int j)
{
	if(i+1==j) return 0;

	int res=INT_MAX;
	for(int k=i+1;k<j;k++)
	{
		res=min(res,matChain(arr,i,k)+matChain(arr,k,j)+(arr[i]*arr[k]*arr[j]));
	}
	return res;
}

// Matrix Chain Multiplication | DP Tabulation
int matChainTab(int arr[],int n)
{
	int dp[n][n];
	for(int i=0;i<n-1;i++)
		dp[i][i+1]=0;

	for(int gap=2;gap<n;gap++)
	{
		for(int i=0;i+gap<n;i++)
		{
			int j=i+gap;
			dp[i][j]=INT_MAX;
			for(int k=i+1;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]+(arr[i]*arr[k]*arr[j]));
			}
		}
	}
	return dp[0][n-1];
}

// Palaindrome Partitioning | Recursive
bool isPalindrome(string s,int i,int j)
{
	while(i<=j)
	{
		if(s[i++]==s[j--])
			return true;
	}
	return false;
}
int palPart(string s,int i,int j)
{
	if(isPalindrome(s,i,j))
		return 0;

	int res=INT_MAX;
	for(int k=i;k<j;k++)
	{
		res=min(res,1+palPart(s,i,k)+palPart(s,k+1,j));
	}
	return res;
}

// Palaindrome Partitioning | DP Tabulation
int palPartTab(string str)
{
	int n=str.length();
	int dp[n][n];
	bool isPal[n][n];

	for(int i=0;i<n;i++)
	{
		dp[i][i]=0;
		isPal[i][i]=true;
	}

	for(int gap=1;gap<n;gap++)
	{
		for(int i=0;i+gap<n;i++)
		{
			int j=i+gap;
			if(isPalindrome(str,i,j))
				dp[i][j]=0;
			else
			{
				dp[i][j]=INT_MAX;
				for(int k=i;k<j;k++)
					dp[i][j]=min(dp[i][j],1+dp[k+1][j]);
			}
		}
	}
	return dp[0][n-1];
}

int main()
{
	int n = 5;
	int n1 = fib(n);
	cout<<"The Fibonacci of Number "<<n<<" is :"<<n1<<endl;
	cout<<"The Fibonacci(Memorization) is :"<<Fibo(5)<<endl; 
	cout<<"The Fibonacci(Tabulation) :"<<Fibonacci(5)<<endl;

	string s1="AXYZ";
	string s2="BAZ";
	cout<<"Longest Common Subsequence :"<<lcs(s1,s2,s1.length(),s2.length())<<endl;
	cout<<"Longest Common Subsequence(Memorization) :"<<lcsMemorization(s1,s2,s1.length(),s2.length())<<endl;
	cout<<"LCS (Tabulation) :"<<lcsTabulation(s1,s2)<<endl;

	int arr[]={1,2,3};
	int n2=sizeof(arr)/sizeof(int);
	cout<<"Coin change :"<<getCount(arr,n2,4)<<endl;
	cout<<"Coin change(Tabulation) :"<<GetCount(arr,n2,4)<<endl;

	string A="ecfbefdcfca";
	string B="badfcbebbf";
	cout<<"Edit Distance(Recursive) :"<<editDistance(A,B,A.length(),B.length())<<endl;
	cout<<"Edit Distance (Tabulation) :"<<editDistanceTabulation(A,B,A.length(),B.length())<<endl;

	int arr1[]={3,4,2,8,10};
	cout<<"LIS (Tabulation) :"<<LIS(arr1,sizeof(arr1)/sizeof(int))<<endl;
	cout<<"LIS (Binary Search: OPtimized) :"<<lis(arr1,sizeof(arr1)/sizeof(int))<<endl;

	cout<<"maxCuts Recursive :"<<maxCuts(23,11,12,13)<<endl;
	cout<<"maxCuts DP Solution :"<<maxCutsTabulation(23,11,12,13)<<endl;

	int coins[]={25,10,5};
	cout<<"Minimum coins to make value (Recursive) :"<<getMin(coins,sizeof(coins)/sizeof(int),30)<<endl;
	cout<<"Minimum coins to make value (Tabulation) :"<<getMinTab(coins,sizeof(coins)/sizeof(int),30)<<endl;

	int arr2[]={3,4,2,1,2,1};
	cout<<"Minimum Jumps to Reach End (Recursive) :"<<minJumps(arr2,sizeof(arr2)/sizeof(int))<<endl;
	cout<<"Minimum Jumps to Reach End (Tabulation) :"<<minJumpsTab(arr2,sizeof(arr2)/sizeof(int))<<endl;

	int val[]={10,40,30,50};
	int wt[]={5,4,6,3};
	cout<<"Knapsack (Recursive) :"<<knapsack(10,wt,val,sizeof(val)/sizeof(int))<<endl;
	cout<<"Knapsack (Tabulation) :"<<knapsackTab(10,wt,val,sizeof(val)/sizeof(int))<<endl;

	int arr3[]={20,5,4,6};
	cout<<"The Optimal Strategy for Game (Recusrive Sol-1) :"<<mainSol(arr3,sizeof(arr3)/sizeof(int))<<endl;
	cout<<"The Optimal Strategy for Game (Recusrive Sol-2) :"<<Sol2(arr3,0,sizeof(arr3)/sizeof(int)-1)<<endl;

	int arr4[]={3,20,4,6,7,30};
	cout<<"Maximum Sum Increasing Subsequence (Tabulation) :"<<maxSumIncreSubseq(arr4,sizeof(arr4)/sizeof(int))<<endl;

	int arr5[]={1,11,2,10,4,5,2,1};
	cout<<"Longest Bitonic Subsequence (Tabulation) :"<<lbs(arr5,sizeof(arr5)/sizeof(int))<<endl;

	struct cityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
	// cout<<"Maximum maxBridges :"<<maxBridges(values,sizeof(values)/sizeof(values[0]))<<endl;

	cout<<"Egg Drop (Tabulation) :"<<eggDrop(3,4)<<endl;

	cout<<"Count number of BSTs possible :"<<countBSTs(4)<<endl;

	int arr6[]={10,5,15,20};
	cout<<"Maximum Sum without consecutives (Recursive) :"<<maxSum(arr6,sizeof(arr6)/sizeof(arr6[0]))<<endl;
	cout<<"Maximum Sum without consecutives (Tabulation) :"<<MaxSum(arr6,sizeof(arr6)/sizeof(arr6[0]))<<endl;
	cout<<"Maximum Sum without consecutives (Tabulation Space Optimized) :"<<MaxSumOptim(arr6,sizeof(arr6)/sizeof(arr6[0]))<<endl;

	int arr7[]={10,5,2,3,6};
	cout<<"Subset Sum Problem (Recursive) :"<<countSubsets(arr7,sizeof(arr7)/sizeof(int),8)<<endl;
	cout<<"Subset Sum Problem (Tabulation) :"<<countSubsetsTab(arr7,sizeof(arr7)/sizeof(int),8)<<endl;

	int arr8[]={2,1,3,4};
	cout<<"Matrix Multiplication (Recursive) :"<<matChain(arr8,0,sizeof(arr8)/sizeof(int))<<endl;
	cout<<"Matrix Multiplication (Tabulation) :"<<matChainTab(arr8,sizeof(arr8)/sizeof(int))<<endl;

	string s="geek";
	cout<<"Palindrome Partition (Recursive) :"<<palPart(s,0,s.length()-1)<<endl;
	cout<<"isPalindrome :"<<isPalindrome(s,0,s.length()-1)<<endl;
	cout<<"Palindrome Partition (Tabulation) :"<<palPartTab(s)<<endl;
	return 0;
}