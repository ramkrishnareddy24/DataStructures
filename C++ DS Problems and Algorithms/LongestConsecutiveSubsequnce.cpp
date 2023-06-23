#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

//Naive Solution
int findLongest(int arr[],int n)
{
	sort(arr,arr+n);
	int res=1;
	int curr=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]==arr[i-1]+1)
		{
			curr++;
			res=max(res,curr);
		}
		else
		{
			curr=1;
		}
	}
	return res;
}

//Efficient Solution
int FindLongest(int arr[],int n)
{
	int res=0;
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);

	for(int i=0;i<n;i++)
	{
		if(s.find(arr[i]-1)==s.end())
		{
			int curr=1;
			while(s.find(arr[i]+curr)!=s.end())
			{
				curr++;
				res=max(res,curr);
			}
		}
	}
	return res;
}

int main()
{
	int arr[]={1,9,3,4,2,10,13};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<findLongest(arr,n)<<" ";
	cout<<FindLongest(arr,n);
	return 0;
}