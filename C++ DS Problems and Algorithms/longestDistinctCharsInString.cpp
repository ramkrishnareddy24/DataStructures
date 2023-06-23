#include<bits/stdc++.h>
using namespace std;

//Niave Solution  O(n^3)
bool areDistict(string str,int i,int j)
{
	vector<bool> visited(256);
	for(int k=i;k<=j;k++)
	{
		if(visited[str[i]]==true)
			return false;
		visited[str[i]]=true;
	}
	return true;
}

int longestDistinct(string str)
{
	int n=str.length();
	int res=0;

	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(areDistict(str,i,j))
				res=max(res,j-i+1);
		return res;
}

//Better Solution O(n^2)
int LongestDistinct(string str)
{
	int n=str.length();
	int res=0;

	for(int i=0;i<n;i++)
	{
		vector<bool> visited(256);
		for(int j=i;j<n;j++)
			if(visited[str[j]]==true)
				break;
			else
			{
				res=max(res,j-i+1);
				visited[str[j]]=true;
			}
	}
	return res;
}

//Efficient Solution O(n)
int LONGestDistinct(string str)
{
	int res=0;
	int n=str.length();

	vector<int> prev(256,-1);

	int i=0;
	for(int j=0;j<n;j++)
	{
		i=max(i,prev[str[j]]+1);
		int maxEnd=j-i+1;
		res=max(res,maxEnd);
		prev[str[j]]=j;
	}
	return res;
}

int main()
{
	string str="abcdvvbabcdefghij";
	cout<<longestDistinct(str)<<endl;
	cout<<LongestDistinct(str)<<endl;
	cout<<LONGestDistinct(str)<<endl;
}