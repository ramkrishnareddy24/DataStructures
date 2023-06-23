#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int precedence(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return -1;
}

void infixToPostfix(string str)
{
	stack<char> s;
	string result;

	for(int i=0;i<str.length();i++)
	{
		char c=str[i];

		if((c>='a' && c<='z') || (c<='A' && c<='Z') || (c>='0' && c<='9'))
			result+=c;
		else
		if(c=='(')
			s.push('(');
		else
		if(c==')')
		{
			while(s.top()!='(')
			{
				result+=s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while(!s.empty() && precedence(str[i])<=precedence(s.top()))
			{
				result+=s.top();
				s.pop();
			}
			s.push(c);
		}

	}
	while(!s.empty())
	{
		result+=s.top();
		s.pop();
	}

	cout<<result<<endl;
}

void InfixToPostfix(string str)
{
	stack<char> s;
	string result;

	for(int i=0;i<str.length();i++)
	{
		char c=str[i];

		if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
			result+=c;
		else if(c=='(')
			s.push('(');
		else if(c==')')
		{
			while(s.top()!='(')
			{
				result+=s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while(!s.empty() && precedence(str[i])<=precedence(s.top()))
			{
				result+=s.top();
				s.pop();
			}
			s.push(c);
		}
	}

	while(!s.empty())
	{
		result+=s.top();
		s.pop();
	}

	cout<<result<<endl;
}

int main()
{
	string exp="a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	InfixToPostfix(exp);
	return 0;
}