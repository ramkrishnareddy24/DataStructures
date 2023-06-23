#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countFreq(int arr[],int n)
{
	unordered_map<int,int> mp;

	for(int i=0;i<n;i++)
		mp[arr[i]]++;

	//sort(arr,arr+n);
	for(auto x:mp)
		cout<<x.first<<" "<<x.second<<endl;
}

int main()
{
	int arr[]={1,1,2,2,3,3,3,4,5,5,6};
	int n=sizeof(arr)/sizeof(int);
	
	countFreq(arr,n);
}