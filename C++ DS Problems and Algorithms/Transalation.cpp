#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void translate(string s,string t)
{
	reverse(s.begin(),s.end());
	
	if(s==t)
		cout<<"YES";
	else
		cout<<"NO";
}

int main()
{
	string s;
	cin>>s;
	string t;
	cin>>t;

	translate(s,t);
}