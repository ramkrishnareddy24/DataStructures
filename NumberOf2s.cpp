#include<bits/stdc++.h>
using namespace std;

int numberOf2s(int n)
{
	string s="";
	for(int i=0;i<=n;i++)
		s+=to_string(i);

	int count=0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='2')
			count++;
	
	return count;
}

int main()
{
	int n=30;
	int num=numberOf2s(n);
	cout<<num;
	return 0;
}