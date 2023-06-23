#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string str)
{
	stack<int> s;
	char x;

	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
			s.push(str[i]);
		else
		{
			if(s.empty())
				return false;

			switch(str[i])
			{
				case ')': x = s.top();
						  s.pop();
						  if(x=='{' || x=='[')
						  	return false;
						  break;
				case '}': x = s.top();
						  s.pop();
						  if(x=='(' || x=='[')
						  	return false;
						  break;
				case ']': x=s.top();
						  s.pop();
						  if(x=='(' || x=='{')
						  	return false;
						  break;
			}
		}
	}
	return (s.empty()==true);
}

int main()
{
	string str="(]";
	cout<<isBalanced(str);

	return 0;
}