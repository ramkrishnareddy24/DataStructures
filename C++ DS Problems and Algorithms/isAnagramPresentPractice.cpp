#include<bits/stdc++.h>
using namespace std;

int areSame(int countTxt[],int countPat[])
{
	for(int i=0;i<256;i++)
	{
		if(countTxt[i]!=countPat[i])
			return false;
	}
	return true;
}

//Efficient Solution
bool isAnagramPresent(string txt,string pat)
{
	int countTxt[256]={0};
	int countPat[256]={0};

	for(int i=0;i<pat.length();i++)
	{
		countTxt[txt[i]]++;
		countPat[pat[i]]++;
	}

	for(int i=pat.length();i<txt.length();i++)
	{
		if(areSame(countTxt,countPat))
			return true;

		countTxt[txt[i]]++;
		countTxt[txt[i-pat.length()]]--;
	}
	return false;
}



int main()
{
	string Txt="geeksforgeeks";
	string Pat="eekgs";

	cout<<isAnagramPresent(Txt,Pat);

	return 0;
}