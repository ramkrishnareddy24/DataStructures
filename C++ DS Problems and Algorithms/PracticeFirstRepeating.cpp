#include<bits/stdc++.h>
using namespace std;

//Naive Solution O(n^2)
int firstRepeating_Naive(string str)
{
	for(int i=0;i<str.length();i++)
	{
		for(int j=i+1;j<str.length();j++)
			if(str[j]==str[i])
				return i;
	}
	return -1;
}

//Efficient Solution
int FirstRepeating(string str)
{
	int res=INT_MAX;
	int fI[256];
	for(int i=0;i<256;i++)
		fI[i]=-1;

	for(int i=0;i<str.length();i++)
	{
		if(fI[str[i]]==-1)
			fI[str[i]]=i;
		else
			res=min(res,fI[str[i]]);
	}
	return (res==INT_MAX)?-1:res;
}

//Better Efficient Solution(ALT)
int firstRepeating(string str)
{
	int res=INT_MAX;
	int fI[256];
	for(int i=0;i<256;i++)
		fI[i]=-1;

	for(int i=str.length()-1;i>=0;i--)
	{
		if(fI[str[i]]==-1)
			fI[str[i]]=i;
		else
			res=fI[str[i]];
	}
	return (res==INT_MAX)?-1:res;
}

int main()
{
	string s="geeksforgeeks";
	cout<<firstRepeating(s)<<endl;
	cout<<FirstRepeating(s)<<endl;
	cout<<firstRepeating_Naive(s);

	return 0;
}