#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds)
{
	if(ind==arr.size())
	{
		if(target==0)
		{
			ans.push_back(ds);
		}
		return;
	}

	// pickup
	if(arr[ind]<=target){
		ds.push_back(arr[ind]);
		findCombination(ind,target-arr[ind],arr,ans,ds);
		ds.pop_back();
	}

	// not pickup
	findCombination(ind+1,target,arr,ans,ds);
}

vector<vector<int>> combinationSum(vector<int> &v, int target)
{
	vector<vector<int>> ans;
	vector<int> ds;
	findCombination(0,target,v,ans,ds);
	return ans;
}

int main()
{
	vector<int> v ={2,3,6,7};
	int target = 7;

	vector<vector<int>> ans = combinationSum(v,target);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}