#include<iostream>
#include<cstring>
using namespace std;

int stringMatch(string s1,string s2)
{
	int i,j,n=s1.length(),m=s2.length();
	for(int i=0;i<n-m;)
	{
		for(int j=0;j<m;j++)
			if(s1[i+j]!=s2[j])
				break;
			if(j==m) break;
			cout<<i<<" ";
			if(j==0) i++;
			i=i+j;

	}

}

int main()
{
	string s1="ABCDE";
	string s2="AB";

	cout<<stringMatch(s1,s2);

	return 0;
}