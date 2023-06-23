#include<iostream>
#include<cstring>
using namespace std;

bool Anagram(string s1,string s2)
{
	if(s1.length()!=s2.length())
		return false;

	int count[256]={0};

	for(int i=0;i<s1.length();i++)
		count[s1[i]]++;
	for(int i=0;i<s1.length();i++)
		count[s2[i]]--;
	for(int i=0;i<256;i++)
		if(count[i]!=0)
			return false;
	return true;
}

vector<string> removeAnagrams(vector<string>& words) {
	for(int i=0;i<words.size();i++)
	{
		for(int j=i+1;j<words.size();j++)
		{
			if(Anagram(i,j))
				words.erase(words[i]);
		}
	}
	return words;        
} 

int main()
{
	string s1="geeks";
	string s2="ekegs";

	cout<<Anagram(s1,s2);

}