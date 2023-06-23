#include<bits/stdc++.h>
using namespace std;

vector<int> missingAndRepeating(int arr[],int n)
{
	vector<int> v;
	int rep=0;
	int sum=0;
	int totalSum=(n*(n+1))/2;

	unordered_set<int> s;
	unordered_map<int,int> m;

	for(int i=0;i<n;i++)
	{
		m[arr[i]]++;
		s.insert(arr[i]);
	}

	for(auto x:s)
		sum+=x;

	for(auto x:m)
		if(x.second==2)
			rep=x.first;

	int miss=totalSum-sum;

	v.push_back(rep);
	v.push_back(miss);
	
	return v;
}

int main()
{
	int arr[]={3,1,2,5,3};
	int n=sizeof(arr)/sizeof(int);
	vector<int> v=missingAndRepeating(arr,n);
	for(auto x:v)
		cout<<x<<" ";
	return 0;
}