#include<bits/stdc++.h>
using namespace std;

int tripletSum(int v[],int n,int sum)
{
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int k=j+1;j<n;j++)
			{
				if(v[i]+v[j]+v[k]==sum){
					cout<<v[i]<<" "<<v[j]<<" "<<v[k];
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int v[]={1, 4, 45, 6, 10, 8};
	int n=sizeof(v)/sizeof(int);
	int sum=22;
	int ans = tripletSum(v,n,sum);

	return 0;
}