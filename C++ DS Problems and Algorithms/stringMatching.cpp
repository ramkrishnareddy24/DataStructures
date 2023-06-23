#include<bits/stdc++.h>
using namespace std;

//String Searching Algo
int stringMatching1(string txt,string pat)
{
	int n=txt.length(),m=pat.length();

	for(int i=0;i<n-m;i++)
	{
		int j;
		for(int j=0;j<m;j++)
		{
			if(txt[i+j]!=pat[j])
				break;
		}
		if(j==m)
			return i;
	}
}

int stringMatching2(string txt,string pat)
{
	return (txt.find(pat)!=string::npos)?1:0;
}

int main()
{
	string s1="ABCDABCE";
	string s2="ABCE";

	cout<<stringMatching1(s1,s2)<<endl;
	cout<<stringMatching2(s1,s2);

	return 0;
}