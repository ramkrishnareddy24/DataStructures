#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int longPropPreSuff(string str,int n)
{
	for(int len=n-1;len>0;len--)
	{
		bool flag=true;
		for(int i=0;i<len;i++)
			if(str[i]!=str[n-len+i])
				flag=false;
		if(flag==true)
			return len;
	}
	return 0;
}

void fillLPS(string str,int lps[])
{
	for(int i=0;i<str.length();i++)
		lps[i]=longPropPreSuff(str,i+1);

	for(int i=0;i<str.length();i++)
		cout<<lps[i]<<" ";
}

//Efficient Solution
void FillLPS(string str,int lps[])
{
	int len=0;
	int n=str.length();
	lps[0]=0;
	int i=1;

	while(i<n)
	{
		if(str[i]==str[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len==0)
			{
				lps[i]=0;
				i++;
			}
			else
			{
				len=lps[len-1];
			}
		}
	}
}

int main()
{
	string str="ababacab";
	int n=str.length();
	int lps[n];
	fillLPS(str,lps);
	cout<<endl;

	FillLPS(str,lps);
	for(int i=0;i<n;i++)
		cout<<lps[i]<<" ";
}