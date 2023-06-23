#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s)
{
	vector<int> v(256,-1);

	int left=0,right=0;
	int len=0;
	int n=s.size();
	while(right<n)
	{
		if(v[s[right]]!=-1)
			left = max(v[s[right]]+1,left);

		v[s[right]] = right;

		len = max(right-left+1,len);
		right++;
	}
	return len;
}

int main()
{
	string s = "abcabcbb";
	cout<<longestSubstring(s)<<endl;
}