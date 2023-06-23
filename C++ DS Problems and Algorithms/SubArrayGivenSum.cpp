#include<iostream>
#include<unordered_set>
using namespace std;

//Naive Solution
bool isSum(int arr[],int n,int sum)
{
	for(int i=0;i<n;i++)
	{
		int curr_sum=0;
		for(int j=i;j<n;j++)
		{
			curr_sum+=arr[j];
			if(curr_sum==sum)
				return true;
		}
	}
	return false;
}

//Efficient Solution
bool IsSum(int arr[],int n,int sum)
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

int main()
{
	int arr[]={5,8,6,13,3,-1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int sum=15;
	cout<<isSum(arr,n,sum)<<" ";
	cout<<IsSum(arr,n,sum);
	return 0;
}