#include<bits/stdc++.h>
using namespace std;

vector<int> separate(vector<int> v)
{
	vector<int> ans;

	for(int i=0;i<v.size();i++)
	{
		string tmp=to_string(v[i]);
		for(auto x:tmp)
			ans.push_back(x-'0');
	}
	return ans;
}

int main()
{
	vector<int> v={32,1};
	vector<int> res=separate(v);

	for(auto x:res){
		
			cout<<x<<endl;
	}
}