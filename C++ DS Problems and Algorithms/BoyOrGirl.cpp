#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	string s,res;
	cin>>s;

	int count[256]={0};

	for(int i=0;i<s.length();i++)
	{
		if(count[s[i]]==0)
		{
			count[s[i]]=1;
			res=res+s[i];
		}
	}
	cout<<res<<endl;
	if(res.length()%2==0)
	{
		cout<<"CHAT WITH HER!";
	}
	else{
		cout<<"IGNORE HIM!";
	}

	return 0;
}