#include<iostream>
#include<cstring>
using namespace std;

int word(string s)
{
	int count1=0,count2=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a' && s[i]<='z')
			count1++;
		if(s[i]>='A' && s[i]<='Z')
			count2++;
	}

	if(count1>count2 || count1==count2)
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>='A' && s[i]<='Z')
			s[i]=s[i]+32;
		}

	}

	if(count1<count2)
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>='a' && s[i]<='z')
				s[i]=s[i]-32;
		}
	}

	cout<<s<<endl;

	return 0;
}

int main()
{
	string s;
	cin>>s;

	word(s);
}