#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
	vector<vector<int>> mergedIntervals;

	if(intervals.size()==0)
		return mergedIntervals;

	sort(intervals.begin(),intervals.end());
	vector<int> tempInterval=intervals[0];

	for(auto it:intervals)
	{
		if(it[0]<=tempInterval[1])
		{
			tempInterval[1]=max(it[1],tempInterval[1]);
		}
		else
		{
			mergedIntervals.push_back(tempInterval);
			tempInterval=it;
		}
	}
	mergedIntervals.push_back(tempInterval);
	return mergedIntervals;
}

int main()
{
	vector<vector<int>> v{{1,2},{2,6},{8,10}};
	vector<vector<int>> ans=mergeIntervals(v);

	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[0].size();j++)
		{
				cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}