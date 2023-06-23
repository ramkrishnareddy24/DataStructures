#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int maxConsecutiveOnes(bool arr[],int n)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=i;j<n;j++)
		{
			if(arr[j]==1)
				cnt++;
			else
				break;
		}
		res=max(res,cnt);
	}
	return res;
}

//Efficient Solution
int MaxConsecutiveOnes(bool arr[],int n)
{
	int res=0;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
			cnt=0;
		else
		{
			cnt++;
			res=max(res,cnt);
		}
	}
	return res;
}

int main()
{
	bool arr[]={1,1,1,0,1,1,1,1,1,0,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<maxConsecutiveOnes(arr,n)<<" ";
	cout<<MaxConsecutiveOnes(arr,n);
	return 0;
}

