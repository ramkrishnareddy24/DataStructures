#include<bits/stdc++.h>
using namespace std;

int longestConsectiveOnes(int n)
{
	int bi[32];
	for(int i=0;n>0;i++)
	{
		bi[i]=n%2;
		n=n/2;
	}

	int res=0;
	int curr=0;
	for(int i=0;i<n;i++)
	{
		if(bi[i]==0)
			curr=0;
		else
		{
			curr++;
			res=max(res,curr);
		}
	}
	return res;
}

int main()
{
	int n=14;
	cout<<longestConsectiveOnes(n);
	return 0;
}