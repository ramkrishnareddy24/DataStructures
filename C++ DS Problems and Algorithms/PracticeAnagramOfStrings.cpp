#include<iostream>
#include<cstring>
using namespace std;

//Efficient Solution
bool anagram(string s1,string s2)
{
	if(s1.length()!=s2.length())
		return false;

	int count[256]={0};
	for(int i=0;i<s1.length();i++)
		count[s1[i]]++;

	for(int i=0;i<s2.length();i++)
		count[s2[i]]--;

	for(int i=0;i<256;i++)
		if(count[i]!=0)
			return false;
	return true;
}

int frequency(string s)
{
	int c=0;
	int count[256]={0};
	for(int i=0;i<s.length();i++)
	{
		count[s[i]]++;
		c++;
	}
	return c;
}

int main()
{
	string s1="geeks";
	string s2="eegks";
	cout<<anagram(s1,s2); cout<<endl;
	cout<<frequency(s1);

	return 0;
}