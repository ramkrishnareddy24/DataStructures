#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int countSet(int n)
{
	int res=0;
	while(n>0)
	{
		if(n%2!=0)
			res++;
		n=n/2;
	}
	return res;
}

//Efficient Solution O(n)
//Brian Kurningam's Algo
int CountSet(int n)
{
	int res=0;
	while(n>0)
	{
		n=n&(n-1);
		res++;
	}
	return res;
}

//O(1) Solution
int table[256];
void initialize()
{
	table[0]=0;
	for(int i=1;i<256;i++)
		table[i]=(i&1)+table[i/2];
}

int count(int n)
{
	int res=table[n&0xff];
	n=n>>8;
	res=res+table[n&0xff];
	n=n>>8;
	res=res+table[n&0xff];
	n=n>>8;
	res=res+table[n&0xff];
	n=n>>8;
	return res;
}

int main()
{
	int n=5;
	cout<<countSet(n);
	cout<<" "<<CountSet(n);
	cout<<" "<<count(n);
	return 0;
}