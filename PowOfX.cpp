#include<bits/stdc++.h>
using namespace std;

int powOfX(int x,int n)
{
	int res=1;
	for(int i=0;i<n;i++)
		res=res*x;
	return res;
}

int main()
{
	int x=2,n=10;
	int ans=powOfX(x,n);
	cout<<ans;

	return 0;
}