#include<bits/stdc++.h>
using namespace std;

// Linear Search
bool searchIn2DMatrix(vector<vector<int>> v,int target)
{
	int n=v.size();
	int m=v[0].size();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(target==v[i][j])
				return true;
	return false;
}

// Binary Search Matrix
bool searchInMatrix(vector<vector<int>> v,int target)
{
	if(v.size()==0) return false;

	int n=v.size();
	int m=v[0].size();

	int lo=0,hi=n*m-1;
	while(lo<=hi)
	{
		int mid=(lo+hi)/2;

		if(v[mid/m][mid%m]==target)
			return true;

		if(target<v[mid/m][mid%m])
			hi=mid-1;
		else
			lo=mid+1;
	}
	return false;
}

int main()
{
	vector<vector<int>> v={{1,3,5,7},{10,11,16,20},{20,30,34,60}};
	int target=3;
	bool ans=searchInMatrix(v,target);
	cout<<ans;
	return 0;
}