#include<bits/stdc++.h>
using namespace std;

void fillLPS(string str,int lps[])
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

//Efficient Solution
void KMP(string pat,string txt)
{
	int N=txt.length();
	int M=pat.length();
	int lps[M];
	fillLPS(pat,lps);

	int i=0,j=0;
	while(i<N)
	{
		if(txt[i]==pat[j])
		{
			i++; j++;
		}

		if(j==M)
		{
			cout<<(i-j)<<" ";
			j=lps[j-1];
		}
		else if(i<N && txt[i]!=pat[j])
		{
			if(j==0)
				i++;
			else
				j=lps[j-1];
		}
	}
}

int main()
{
	string txt="ababcababcad";
	string pat="abc";
	KMP(pat,txt);
}