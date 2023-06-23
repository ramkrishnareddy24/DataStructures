#include<bits/stdc++.h>
using namespace std;

vector<string> split(string &str,int n)
{
	vector<string> substrings;

	for(int i=0;i<str.length();i+=n)
	{
		substrings.push_back(str.substr(i,n));
	}
	return substrings;
}

void splitString(string str)
{
	int n=str.length()/2;
	vector<string> v;
	for(int i=0;i<str.length();i+=n)
	{
		v.push_back(str.substr(i,n));
	}

	for(auto x:v)
		cout<<x<<" ";
}

int main()
{
	string str="abcdefgh";
	int n=str.length();
	n=n/2;
	vector<string> tokens=split(str,n);

	for(auto &x:tokens)
	{
		cout<<x<<endl;
	}

	splitString(str);
	return 0;
}