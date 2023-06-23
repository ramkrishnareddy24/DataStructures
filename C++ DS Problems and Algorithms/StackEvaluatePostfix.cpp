#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
int evaluatePostfix(string str)
{
    stack<int> s;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i]-'0');
        }
        else
        {
            int n1 = s.top();
            s.pop();
            
            int n2 = s.top();
            s.pop();
            
            if(str[i] == '*')
            {
                s.push(n1*n2);
            }
            else if(str[i] == '/')
            {
                s.push(n2/n1);
            }
            else if(str[i] == '+')
            {
                s.push(n1+n2);
            }
            else if(str[i] == '-')
            {
                s.push(n2-n1);
            }
        }
    }
    return s.top();
}


int main()
{
	string str="123+*8-";
	cout<<evaluatePostfix(str)<<" ";
	return 0;
}