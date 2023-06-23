#include<iostream>
#include<unordered_map>
using namespace std;

//Naive Solution
int longSubArray(int arr[],int n)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		int c0=0,c1=0;
		for(int j=i;j<n;j++)
		{
			if(arr[j]==0)
				c0++;
			else
				c1++;

			if(c0==c1)
			res=max(res,j-i+1);
		}
	}
	return res;
}

//Efficient Solution
int LongSubArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
		if(arr[i]==0)
			arr[i]=-1;

	unordered_map<int,int> m;
	int res=0;
	int pref_sum=0;
	int sum=0;

	for(int i=0;i<n;i++)
	{
		pref_sum+=arr[i];

		if(pref_sum==sum)
			res=i+1;
		if(m.find(pref_sum)==m.end())
			m.insert({pref_sum,i});
		if(m.find(pref_sum-sum)!=m.end())
			res=max(res,i-m[pref_sum-sum]);
	}
	return res;
}

int main()
{
	int arr[]={1,1,1,1,0,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<longSubArray(arr,n);
	cout<<LongSubArray(arr,n);
	return 0;
}