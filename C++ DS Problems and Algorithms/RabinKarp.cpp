#include<bits/stdc++.h>
using namespace std;
#define d 256

//Efficient Solution 
void rabinKarp(string txt,string pat,int m,int n)
{
	int q=101;
	int h=1;
	for(int i=1;i<=m-1;i++)
		h=(h*d)%q;

	int p=0,t=0;
	for(int i=0;i<m;i++)
	{
		p=(p*d+pat[i])%q;
		t=(t*d+txt[i])%q;
	}

	for(int i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			bool flag=true;
			for(int j=0;j<m;j++)
				if(txt[i+j]!=pat[j])
				{
					flag=false;
					break;
				}
				if(flag==true)
					cout<<i<<" ";
		}

		if(i<n-m)
		{
			t=(d*(t-txt[i]*h)+txt[i+m])%q;
			if(t<0)
				t=t+q;
		}
	}
}

void RabinKarp(string txt,string pat,int m,int n)
{
	int q=101;
	int h=1;
	for(int i=1;i<=m-1;i++)
		h=(h*d)%q;

	int t=0,p=0;
	for(int i=0;i<m;i++)
	{
		p=(p*d+pat[i])%q;
		t=(t*d+txt[i])%q;
	}

	for(int i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			bool flag=true;
			for(int j=0;j<m;j++)
				if(txt[i+j]!=pat[j])
				{
					flag=false;
					break;
				}
				if(flag==true)
					cout<<i<<" ";
		}
		if(i<n-m)
		{
			t=(d*(t-txt[i]*h)+txt[i+m])%q;
			if(t<0)
				t=t+q;
		}
	}
}



int main()
{
	string txt="abdabccdabc";
	string pat="abc";
	int n=txt.length();
	int m=pat.length();
	rabinKarp(txt,pat,m,n);
	cout<<endl;
	RabinKarp(txt,pat,m,n);
	return 0;
}