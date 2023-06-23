#include<bits/stdc++.h>
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

// int firstRepeating(string s1)
// {
// 	int res=INT_MAX;
// 	string fI[256]={-1};

// 	for(int i=s1.length()-1;i>=0;i--)
// 		if(fI[s1[i]]==-1)
// 			fI[s1[i]]=i;
// 		else
// 			res=fI[s1[i]];

// 	return (res==INT_MAX)?-1:res;
// }

// int firstNonRepeating(string s1)
// {
// 	int res=INT_MAX;
// 	int fI[256];
// 	for(int i=0;i<256;i++)
// 		fI[i]=-1;

// 	for(int i=0;i<s1.length();i++)
// 	{
// 		if(fI[s1[i]]==-1)
// 			fI[s1[i]]=i;
// 		else
// 			fI[s1[i]]=-2;
// 	}

// 	for(int i=0;i<256;i++)
// 		if(fI[i]>=0)
// 			res=min(res,fI[i]);

// 	return (res==INT_MAX)?-1:res;
// }

void reverse(string str)
{
	int n=str.length();
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		swap(str[low],str[high]);
		low++;
		high--;
	}
	cout<<str<<endl;
}

bool palindrome(string str)
{
	int n=str.length();
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		if(str[low]!=str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

int stringMatching(string txt,string pat)
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

int main()
{
	string s1="geeks";
	string s2="ekegs";
	cout<<"Anagram :"<<Anagram(s1,s2)<<endl;

	// string s="geeksforgeeks";
	// cout<<firstRepeating(s);
	// cout<<firstNonRepeating(s);

	string str="Hello";
	cout<<"Reverse :";reverse(str);

	string ss="TeneT";
	cout<<"palindrome :"<<palindrome(ss)<<endl;

	string s11="ABCDABCE";
	string s22="DAB";

	cout<<"stringMatching :"<<stringMatching(s11,s22)<<endl;

	return 0;
}