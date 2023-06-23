#include<bits/stdc++.h>
using namespace std;

void allSubsequenceSumK(int ind,vector<int> &ds,int s,int sum,int arr[],int n)
{
	if(ind>=n)
	{
		if(s==sum)
		{
			for(auto x:ds)
				cout<<x<<" ";
			cout<<endl;
		}
		return;
	}

	// take or pick
	ds.push_back(arr[ind]);
	s+=arr[ind];
	allSubsequenceSumK(ind+1,ds,s,sum,arr,n);
	ds.pop_back();
	s-=arr[ind];

	// not take or not pick
	allSubsequenceSumK(ind+1,ds,s,sum,arr,n);
}

bool oneSubsequenceSumK(int ind,vector<int> &ds,int s,int sum,int arr[],int n)
{
	if(ind>=n)
	{
		if(s==sum)
		{
			for(auto x:ds)
				cout<<x<<" ";
			cout<<endl;
			return true;
		}
		else
			return false;
	}
	

	// take or pick
	ds.push_back(arr[ind]);
	s+=arr[ind];
	if(oneSubsequenceSumK(ind+1,ds,s,sum,arr,n)==true) return true;
	ds.pop_back();
	s-=arr[ind];

	// not take or not pick
	if(oneSubsequenceSumK(ind+1,ds,s,sum,arr,n)==true) return true;

	return false;
}

int countSubsequenceSumK(int ind,vector<int> &ds,int s,int sum,int arr[],int n)
{
	if(s > sum) return 0;
	
	if(ind>=n)
	{
		if(s==sum)
		{
			return 1;
		}
		else
			return 0;
	}
	

	// take or pick
	s+=arr[ind];
	int l = countSubsequenceSumK(ind+1,ds,s,sum,arr,n);
	s-=arr[ind];

	// not take or not pick
	int r = countSubsequenceSumK(ind+1,ds,s,sum,arr,n);

	return l+r;
}


int main()
{
	int arr[]={1,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int sum=2;

	vector<int> ds;
	cout<<countSubsequenceSumK(0,ds,0,sum,arr,n);
}