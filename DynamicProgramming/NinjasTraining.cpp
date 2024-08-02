#include<bits/stdc++.h>
using namespace std;

//Recursive Solution
int f(int day, int last,vector<vector<int>>& points){
	if(day == 0){
		int maxi = 0;
		for(int task = 0; task < 3; task++){
			if(task != last){
				maxi = max(maxi, points[0][task]);
			}
		}
		return maxi;
	}
	int maxi = 0;

	for(int task = 0; task < 3; task++){
		if(task != last){
			int point = points[day][task] + f(day-1,task,points);
			maxi = max(maxi,point);
		}
	}
	return maxi;
}

int ninjasTraining(int n, vector<vector<int>> & points){
	return f(n-1,points);
}

//Memoization 
int f(int day, int last,vector<vector<int>>& points, vector<vector<int>>& dp){
	if(day == 0){
		int maxi = 0;
		for(int task = 0; task < 3; task++){
			if(task != last){
				maxi = max(maxi, points[0][task]);
			}
		}
		return maxi;
	}

	if(dp[day][last] != -1) 
		return dp[day][last];

	int maxi = 0;

	for(int task = 0; task < 3; task++){
		if(task != last){
			int point = points[day][task] + f(day-1,task,points,dp);
			maxi = max(maxi,point);
		}
	}
	return dp[day][last] = maxi;
}

int ninjasTraining(int n, vector<vector<int>> & points){
	vector<vector<int>> dp(n,vector<int>(4,-1));
	return f(n-1,points);
}

//Tabulation



int main()
{

}