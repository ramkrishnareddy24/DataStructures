#include<bits/stdc++.h>
using namespace std;

int countDistinct(int arr[],int n)
{
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);
	return s.size();
}

void countFrequency(int arr[],int n)
{
	unordered_map<int,int> m;

	for(int i=0;i<n;i++)
		m[arr[i]]++;

	cout<<"countFrequency"<<endl;
	for(auto x:m)
		cout<<x.first<<" "<<x.second<<endl;
}

bool uniqueOccurences(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;

	unordered_set<int> s;
	for(auto x:mp)
		s.insert(x.second);

	if(mp.size()==s.size())
		return true;
	return false;
}

bool isPairSum(int arr[],int n,int sum)
{
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);

	for(int i=0;i<n;i++)
	if(s.find(sum-arr[i])!=s.end())
		return true;
	return false;
}

bool subArrayZeroSum(int arr[],int n)
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

bool subArrayZeroSUM(int arr[],int n)
{
	int pref_sum=0;
	unordered_set<int> s;

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

bool subArrayGivenSum(int arr[],int n,int sum)
{
	for(int i=0;i<n;i++)
	{
		int curr_sum=0;
		for(int j=i;j<n;j++)
		curr_sum+=arr[j];

		if(curr_sum==sum)
		return true; 
	}
	return false;
}


bool subArrayGivenSUM(int arr[],int n,int sum)
{
	int pref_sum=0;
	unordered_set<int> s;

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

vector<int> twoSum(vector<int> arr,int sum)
{
	vector<int> v;
	unordered_map<int,int> mp;

	for(int i=0;i<arr.size();i++)
	{
		if(mp.find(sum-arr[i])!=mp.end())
		{
			v.push_back(mp[sum-arr[i]]);
			v.push_back(i);
		}
		mp[arr[i]]=i;
	}
	return v;
}


int main()
{
	int arr[]={3,4,4,5,5};
	int n=sizeof(arr)/sizeof(int);

	cout<<"countDistinct :"<<countDistinct(arr,n)<<endl;
	countFrequency(arr,n);
	cout<<"uniqueOccurences :"<<uniqueOccurences(arr,n)<<endl;

	vector<int> arr1={2,7,11,15};
	int sum=9;

	vector<int> twoS;
	twoS = twoSum(arr1,18);
	cout<<"twoSum"<<endl;
	for(auto x:twoS)
		cout<<x<<" ";

	return 0;
}