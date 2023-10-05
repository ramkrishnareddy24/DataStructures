#include<bits/stdc++.h>
using namespace std;

string reverse(string s)
{
	int n = s.length();
	int lo = 0,hi = n-1;

	while(lo<hi)
	{
		swap(s[lo],s[hi]);
		lo++;
		hi--;
	}
	return s;
}

string reverseWords(string s)
{
	int n = s.length();
	string ans = "";

	int i=0;
	while(i<n)
	{
		string temp = "";
		while(s[i]==' ' && i<n) i++;
		while(s[i]!=' ' && i<n){
			temp+=s[i];
			i++;
		}
		if(temp.size()>0){
			if(ans.size()==0)
				ans = reverse(temp);
			else
				ans = reverse(temp)+" "+ans;
		}
	}
	return ans;
}

int main()
{
	string str = "Let's take LeetCode contest";
	string s = reverseWords(str);
	cout<<s;
	return 0;
}