//Backtracking Guide
/*
	start point
	while(more possibilties){
		for each path from start point
			check if it is safe path
				if Yes -> select it -> Recursive call
				if No -> continue
			undo this move
	}
*/

//Leetcode || 78. Subsets
class Solution {
public:
	void backtrack(vector<vector<int>>& list,vector<int>& tempList,vector<int>& nums,int start){
		list.push_back(tempList);

		for(int i=start;i<nums.size();i++){
			tempList.push_back(nums[i]);
			backtrack(list,tempList,nums,i+1);
			tempList.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums){
		vector<vector<int>> list;
		vector<int> tempList;

		backtrack(list,tempList,nums,0);
		return list;
	}
};

//Leetcode || 90. Subsets II
class Solution {
public:
	void backtrack(vector<vector<int>>& list,vector<int>& tempList,vector<int>& nums,int start){
		list.push_back(tempList);

		for(int i=start;i<nums.size();i++){
			if(i>start && nums[i]==nums[i-1]) continue;
			tempList.push_back(nums[i]);
			backtrack(list,tempList,nums,i+1);
			tempList.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums){
		vector<vector<int>> list;
		vector<int> tempList;

		backtrack(list,tempList,nums,0);
		return list;
	}
};

//Leetcode || 46. Permutations
class Solution {
public:
	void backtrack(vector<vector<int>>& list,vector<int> tempList,vector<int>& nums,vector<bool>& used){
		if(tempList.size()==nums.size()){
			list.push_back(tempList);
		} else {
			for(int i=0;i<nums.size();i++){
				if(used[i]) continue;

				used[i] = true;
				tempList.push_back(nums[i]);
				backtrack(list,tempList,nums,used);
				used[i] = false;
				tempList.pop_back();
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums){
		vector<vector<int>> list;
		vector<int> tempList;
		vector<bool> used(nums.size(),false);

		backtrack(list,tempList,nums,used);
		return list;
	}
};

//Leetcode || 47. Permutations II
class Solution {
public:
	void backtrack(vector<vector<int>>& list,vector<int> tempList,vector<int>& nums,vector<bool>& used){
		if(tempList.size()==nums.size()){
			list.push_back(tempList);
		} else {
			for(int i=0;i<nums.size();i++){
				if(used[i] || (i>0 && nums[i]==nums[i-1] && !used[i-1])) continue;

				used[i] = true;
				tempList.push_back(nums[i]);
				backtrack(list,tempList,nums,used);
				used[i] = false;
				tempList.pop_back();
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums){
		vector<vector<int>> list;
		vector<int> tempList;
		vector<bool> used(nums.size(),false);

		sort(nums.begin(),nums.end());

		backtrack(list,tempList,nums,used);
		return list;
	}
};

//Leetcode || 77. Combinations
class Solution {
public:
	void backtrack(vector<vector<int>>& list,vector<int>& tempList,int n,int k,int start){
		if(tempList.size()==k){
			list.push_back(tempList);
		} else {
			for(int i=start;i<n;i++){
				tempList.push_back(i);
				backtrack(list,tempList,n,k,i+1);
				tempList.pop_back(i);
			}
		}
	}
	vector<vector<int>> combine(int n,int k){
		vector<vector<int>> list;
		vector<int> tempList;
		backtrack(list,tempList,n,k,1);
		return list;
	}
};






