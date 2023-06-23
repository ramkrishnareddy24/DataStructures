#include<bits/stdc++.h>
using namespace std;

void reverseWords(string str)
{
	vector<string> s;
	string st;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!=' ')
			st+=str[i];
		else
		{
			s.push_back(st);
			st="";
		}
	}
	s.push_back(st);

	for(int i=s.size()-1;i>=0;i--)
		cout<<s[i]<<" ";
}

int main()
{
	string str="I Am Ram";
	reverseWords(str);
	return 0;
}