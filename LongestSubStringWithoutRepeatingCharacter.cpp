#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string str)
{
	if(str.size()==0)
		return 0;

	int maxans=INT_MIN;
	for(int i=0;i<str.length();i++)
	{
		unordered_set<int> s;
		for(int j=i;j<str.length();j++)
		{
			if(s.find(str[j])!=s.end())
			{
				maxans=max(maxans,j-i);
				break;
			}
			s.insert(str[j]);
		}
	}
	return maxans;
}

int lengthOfLongestSubString(string str)
{
	vector<int> mpp(256,-1);

	int left=0,right=0;
	int n=str.size();
	int len=0;

	while(right<n)
	{
		if(mpp[str[right]]!=-1)
			left=max(mpp[str[right]]+1,left);

		mpp[str[right]]=right;

		len=max(len,right-left+1);
		right++;
	}
	return len;
}

int main()
{
	string str="takeUforward";
	int res=longestSubstring(str);
	int ans=lengthOfLongestSubString(str);
	cout<<res<<" "<<ans;
	return 0;
}