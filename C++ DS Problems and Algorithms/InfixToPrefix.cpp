#include<bits/stdc++.h>
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

void infixToPrefix(string str)
{
	stack<char> s;
	string result;

	for(int i=str.length();i>=0;i--)
	{
		char c=str[i];

		if((c>='a' && c<='z') || (c<='A' && c<='Z') || (c>='0' && c<='9'))
			result+=c;
		else
			if(c==')')
				s.push(')');
			else if(c=='(')
			{
				while(s.top()!=')')
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

	// reverse(result);
	cout<<result<<endl;
}

int main()
{
    string s = ("x+y*z/w+u");
    infixToPrefix(s);
    return 0;
}