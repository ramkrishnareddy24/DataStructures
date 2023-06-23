#include<bits/stdc++.h>
using namespace std;

string removeDups(string s)
{
	int count[256]={0};
	string res;

	for(int i=0;i<s.length();i++)
	{
		if(count[s[i]]==0)
		{
			count[s[i]]=1;
			res=res+s[i];
		}
	}
	return res;
}

int main()
{
	string s="abbcbcbcbcbbcbcbcbdddddd";
	cout<<removeDups(s);
	return 0;
}