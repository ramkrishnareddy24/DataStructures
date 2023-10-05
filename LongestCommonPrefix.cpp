#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
	string ans = "";
	int n = strs.size();

	for(int i=0;i<strs[0].length();i++){
		char ch = strs[0][i];
		bool match = true;

		for(int j=1;j<n;j++){
			if(strs[j].size()<i || ch!=strs[j][i]){
				match = false;
				break;
			}
		}
		if(match==false)
			break;
		else
			ans.push_back(ch);
	}
	return ans;
}

int main()
{
	vector<string> strs = {"flower","flow","flight"};
	string ans = longestCommonPrefix(strs);
	cout<<ans;
	return 0;
}