#include<bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
	return isdigit(c);
}

//Effcient Solution
int prefixEvaluation(string str)
{
	stack<int> s;
	int n=str.length();

	for(int i=n-1;i>=0;i--)
	{
		if(isOperand(str[i]))
			s.push(str[i]-'0');
		else
		{
			int n1=s.top();
			s.pop();
			int n2=s.top();
			s.pop();

			if(str[i]=='*')
				s.push(n1*n2);
			else if(str[i]=='/')
				s.push(n2/n1);
			else if(str[i]=='+')
				s.push(n1+n2);
			else if(str[i]=='-')
				s.push(n2-n1);
			else if(str[i]=='^')
				s.push(n2^n1);
		}
	}
	return s.top();
}

int main()
{
	string str="+9*26";
	cout<<prefixEvaluation(str);
	return 0;
}