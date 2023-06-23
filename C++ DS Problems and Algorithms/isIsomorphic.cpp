#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
bool isomorphic(string s1,string s2)
{
	if(s1.length()!=s2.length())
		return false;

	int count1[256]={0};
	int count2[256]={0};

	for(int i=0;i<s1.length();i++)
	{
		count1[s1[i]]++;
		count2[s2[i]]++;

		if(count1[s1[i]]!=count2[s2[i]])
			return false;
	}
	return true;
}


int main()
{
	string s1="aab";
	string s2="xxy";
	cout<<isomorphic(s1,s2);
	return 0;
}