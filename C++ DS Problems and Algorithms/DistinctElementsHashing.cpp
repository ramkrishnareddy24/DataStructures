#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countDistint(int arr[],int n)
{
	unordered_set<int> s;

	for(int i=0;i<n;i++)
		s.insert(arr[i]);

	for(auto x:s)
		cout<<x<<" ";
	cout<<endl;
	return s.size();


}

int main()
{
	int arr[]={10,20,10,40,70,30,20,100};
	int n=sizeof(arr)/sizeof(int);
	cout<<countDistint(arr,n);
}