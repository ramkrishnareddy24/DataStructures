#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;

	for(auto x:mp){
		if(x.second>1)
			return x.first;
	}
	return -1;
}

int main()
{
	int arr[]={1,2,3,4,5,6,2};
	int n=sizeof(arr)/sizeof(int);
	int findDup = findDuplicate(arr,n);
	cout<<findDup;

	return 0;
}