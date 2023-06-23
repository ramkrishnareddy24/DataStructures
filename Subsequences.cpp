#include<bits/stdc++.h>
using namespace std;

void subsequence(int ind,vector<int> &ds,int arr[],int n)
{
	if(ind>=n)
	{
		for(auto x:ds){
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}

	// take or pick particular element from arr
	ds.push_back(arr[ind]);
	subsequence(ind+1,ds,arr,n);
	ds.pop_back();

	// not take or not pick particular element from arr
	subsequence(ind+1,ds,arr,n);
}

int main()
{
	int arr[]={3,1,2};
	int n=sizeof(arr)/sizeof(int);

	vector<int> ds;

	subsequence(0,ds,arr,n);

	return 0;
}