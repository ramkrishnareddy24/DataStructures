#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
int isRotaion(string s1,string s2)
{
	if(s1.length()!=s2.length())
		return false;

	return ((s1+s1).find(s2)!=string::npos);
}

int main()
{
	string s1="ABCD";
	string s2="CDAB";
	cout<<isRotaion(s1,s2);

	return 0;
}