#include<bits/stdc++.h>
using namespace std;

int FirstRepeating(string s1)
{
	int res=INT_MAX;
	int fI[256]={-1};
	for(int i=s1.length()-1;i>=0;i--)
		if(fI[s1[i]]==-1)
			fI[s1[i]]=i;
		else
			res=fI[s1[i]];
		return (res==INT_MAX)?-1:res;

}
 
int main()
{
	string s1="geeksforeeks";

	cout<<FirstRepeating(s1);
}