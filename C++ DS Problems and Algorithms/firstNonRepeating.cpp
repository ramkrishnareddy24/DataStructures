//Interview Question
#include<bits/stdc++.h>
using namespace std;

//Efficient solution
int firstNonRepeating(string str)
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
			fI[str[i]]=-2;
	}

	for(int i=0;i<256;i++)
		if(fI[i]>=0)
			res=min(res,fI[i]);
		
	return (res==INT_MAX)?-1:res;
}

int main()
{
	string s="geeksforgeeks";
	cout<<firstNonRepeating(s);

	return 0;
}