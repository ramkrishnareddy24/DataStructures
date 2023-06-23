#include<iostream>
#include<unordered_set>
using namespace std;

//Naive Solution
bool subArray0sum(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int curr_sum=0;
		for(int j=i;j<n;j++)
		{
			curr_sum+=arr[j];
			if(curr_sum==0)
				return true;
		}
	}
	return false;
}

//Efficient Solution
bool SubArray0sum(int arr[],int n)
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


int main()
{
	int arr[]={1,4,13,-3,-10,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<subArray0sum(arr,n)<<" ";
	cout<<SubArray0sum(arr,n);
	return 0;
}