#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums,int target)
{
	vector<vector<int>> res;

	if(nums.empty())
		return res;

	int n=nums.size();
	sort(nums.begin(),nums.end());

	for(int i=0;i<n;i++)
	{
		int target_3=target-nums[i];
		for(int j=i+1;j<n;j++)
		{
			int target_2=target_3-nums[i];

			int front=j+1;
			int back=n-1;

			while(front<back)
			{
				int twoSum=nums[front]+nums[back];

				if(twoSum<target_2) front++;
				else if(twoSum>target_2) back--;
				else
				{
					vector<int> quadraplet(4,0);
					quadraplet[0]=nums[i];
					quadraplet[1]=nums[j];
					quadraplet[2]=nums[front];
					quadraplet[3]=nums[back];
					res.push_back(quadraplet);

					while(front<back && nums[front]==quadraplet[2]) ++front;
					while(front<back && nums[back]==quadraplet[3]) --back;
				}
			}
			while(j+1 < n && nums[j+1]==nums[j]) ++j;
		}
		while(i+1 < n && nums[i+1]==nums[i]) ++i;
	}
	return res;
}

int main()
{
	vector<int> v={1,0,-1,0,-2,2};
	vector<vector<int>> sum=fourSum(v,0);
	
	for(int i=0;i<sum.size();i++){
		for(int j=0;j<sum[i].size();j++)
			cout<<sum[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}