#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack,string needle)
{
	if(needle=="") return 0;
	int found = haystack.find(needle);
	if(found!=string::npos)
		return found;
	else
		return -1;
}

int main()
{
	string haystack = "adbutsad";
	string needle = "sad";
	int index = strStr(haystack,needle);
	cout<<index;

	return 0;
}