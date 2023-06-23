#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={10,5,18,15};
	int n=sizeof(arr)/sizeof(int);

	sort(arr,arr+n);
	for(auto x:arr)
		cout<<x<<" ";
	cout<<endl;

	sort(arr,arr+n,greater<int>());
	for(int x:arr)
		cout<<x<<" ";

	return 0;
}