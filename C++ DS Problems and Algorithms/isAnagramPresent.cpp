#include<iostream>
#include<cstring>
using namespace std;

bool areSame(int countTxtW[],int countPat[])
{
	int i;
	for(int i=0;i<256;i++)
	{
		if(countTxtW[i]!=countPat[i])
			return false;

	}
	return true;
}

bool isAnagramPresent(string txt,string pat)
{
	int countTxtW[256]={0},countPat[256]={0};

	for(int i=0;i<pat.length();i++)
	{
		countTxtW[txt[i]]++;
		countPat[pat[i]]++;
	}

	for(int i=pat.length();i<txt.length();i++)
	{
		if(areSame(countTxtW,countPat))
			return true;
		countTxtW[txt[i]]++;
		countTxtW[txt[i-pat.length()]]--;
	}
	return false;
}

int main()
{
	string txt="geeksforgeeks";
	string pat="kege";

	cout<<isAnagramPresent(txt,pat);
}