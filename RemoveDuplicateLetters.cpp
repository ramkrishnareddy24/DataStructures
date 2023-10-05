#include<bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string str){
	stack<char> st;
	map<char,int> mp;
	vector<bool> visited(26,false);

	for(int i=0;i<str.size();i++)
		mp[str[i]]++;

	for(int i=0;i<str.size();i++){
		mp[str[i]]--;
		if(visited[str[i]-'a']==false)
		{
			while(!st.empty() && st.top()>str[i] && mp[st.top()]>0)
			{
				visited[st.top()-'a'] = false;
				st.pop();
			}
			st.push(str[i]);
			visited[str[i]-'a'] = true;
		}
	}

	string ans = "";
	while(!st.empty())
	{
		ans+=st.top();
		st.pop();
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	string str = "abccab";
	string ans = removeDuplicateLetters(str);
	cout<<ans;

	return 0;
}