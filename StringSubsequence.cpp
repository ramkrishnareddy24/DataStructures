#include<bits/stdc++.h>
using namespace std;

bool isSubSeq(string s1,string s2)
{
	int n=s1.length();
	int m=s2.length();

	if(n<m) return false;

	int j=0;
	for(int i=0;i<n&&j<m;j++)
	{
		if(s1[i]==s2[j])
			j++;
	}
	return (j==m);
}

int main()
{
	string s1="ABCDEF";
	string s2="ACF";
	if(isSubSeq(s1,s2))
		cout<<"True";
	else
		cout<<"False";
	return 0;
}