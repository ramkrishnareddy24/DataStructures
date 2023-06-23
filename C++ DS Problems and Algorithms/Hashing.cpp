#include<bits/stdc++.h>
using namespace std;

// count Distinct
int countDistinct(int arr[],int n)
{
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);
	return s.size();
}

// count Frequency
void countFrequency(int arr[],int n)
{
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
		m[arr[i]]++;

	for(auto x:m)
		cout<<x.first<<" "<<x.second<<endl;
}

// Unique Ocuurences
bool uniqueOccurrences(int arr[],int n) {
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    
    set<int> s;
    for(auto x:mp)
        s.insert(x.second);

    if(mp.size()==s.size())
        return true;
    return false;

}

// Pair with given sum in unsorted array
bool isPair(int arr[],int n,int sum)
{
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);

	for(int i=0;i<n;i++)
		if(s.find(sum-arr[i])!=s.end())
			return true;

	return false;
}

// Subarray with zero sum
bool subArrayWithZeroSum(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int curr_sum=0;
		for(int j=i;j<n;j++)
			curr_sum+=arr[j];
		if(curr_sum==0)
			return true;
	}
	return false;
}

bool SubArrayWithZeroSum(int arr[],int n)
{
	unordered_set<int> s;
	int pref_sum=0;

	for(int i=0;i<n;i++)
	{
		pref_sum+=arr[i];
		if(s.find(pref_sum)!=s.end())
			return true;
		if(pref_sum==0)
			return true;
		s.insert(pref_sum);
	}
	return false;
}

// SubArray with given Sum
int subArrayWithGivenSum(int arr[],int n,int sum)
{
	for(int i=0;i<n;i++)
	{
		int curr_sum=0;
		for(int j=i;j<n;j++)
			curr_sum+=arr[i];
		if(curr_sum==sum)
			return true;
	}
	return false;
}

int SubArrayWithGivenSum(int arr[],int n,int sum)
{
	unordered_set<int> s;
	int pref_sum=0;
	for(int i=0;i<n;i++)
	{
		pref_sum+=arr[i];

		if(pref_sum==sum)
			return true;

		if(s.find(pref_sum-sum)!=s.end())
			return true;
		s.insert(pref_sum);
	}
	return false;
}

// Longest Subarray with Sum
// int longestSubarrayWithSum(int arr[],int n,int sum)
// {
// 	int res=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		int curr_sum=0;
// 		for(int j=i;j<n;j++)
// 			curr_sum+=arr[j];
// 		if(curr_sum==sum)
// 			res = max(res,j-i+1);
// 	}
// 	return res;
// }

int LongestSubarrayWithSum(int arr[],int n,int sum)
{
	unordered_map<int,int> m;
	int res=0;
	int pref_sum=0;
	for(int i=0;i<n;i++)
	{
		pref_sum+=arr[i];

		if(pref_sum==sum)
			res=i+1;

		if(m.find(pref_sum)==m.end())
			m.insert({pref_sum,i});

		if(m.find(pref_sum-sum)!=m.end())
			res = max(res,i-m[pref_sum-sum]);
	}
	return res;
}

// longest Subarray with equal 0s ans 1s
// int longestSubarrayWith0s1s(int arr[],int n)
// {
// 	int c1=0,c2=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=i;j<n;j++)
// 			if(arr[j]==0)
// 				c1++;
// 			else
// 				c2++;

// 		if(c1==c2)
// 			res=max(res,j-i+1);
// 	}
// 	return res;
// } 

int LongestSubarrayWith0s1s(int arr[],int n)
{
	for(int i=0;i<n;i++)
		if(arr[i]==0)
			arr[i]=-1;

	unordered_map<int,int> m;
	int pref_sum=0;
	int res=0;
	int sum=0;

	for(int i=0;i<n;i++)
	{
		pref_sum+=arr[i];

		if(pref_sum==sum)
			res=i+1;

		if(m.find(pref_sum)==m.end())
			m.insert({pref_sum,i});

		if(m.find(pref_sum-sum)!=m.end())
			res = max(res,i-m[pref_sum-sum]);
	}
	return res;
}

vector<int> twoSum(vector<int> arr,int sum)
{
	vector<int> ans;
	unordered_map<int,int> mp;
	for(int i=0;i<arr.size();i++)
	{
		if(mp.find(sum-arr[i])!=mp.end())
		{
			ans.push_back(mp[sum-arr[i]]);
			ans.push_back(i);
		}
		mp[arr[i]]=i;
	}
	return ans;
}

int main()
{
	int arr[]={15,12,13,12,13,13,18};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<countDistinct(arr,n)<<endl;
	countFrequency(arr,n);

	int arr1[]={1,2};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    cout<<uniqueOccurrences(arr1,n1);

    cout<<endl<<"twoSum :"<<endl;
    vector<int> arr2 = {2,7,11,15};
    int target=9;
    vector<int> twoS;
    twoS = twoSum(arr2,target);
    for(auto x:twoS)
    	cout<<x<<" ";
}