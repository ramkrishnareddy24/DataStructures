#include<bits/stdc++.h>
using namespace std;

//Method-1 (leftshift)
void KthBit(int n,int k)
{
	if((n&(1<<k-1))!=0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

//Method-2 (rightshift)
void kthBit(int n,int k)
{
	if((n>>k-1)&1!=0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main()
{
	int n=5;
	int k=3;
	KthBit(n,k);
	kthBit(n,k);
	return 0;
}
