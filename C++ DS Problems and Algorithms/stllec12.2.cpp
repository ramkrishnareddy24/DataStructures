#include<iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;

int main()
{
	set<pair<int,int> > s;
	s.insert(make_pair(10,1));
	s.insert(make_pair(20,1));
	s.insert(make_pair(20,100));
	s.insert(make_pair(5,1));
	s.insert(make_pair(5,3));
	s.insert(make_pair(5,4));

	auto it = s.lower_bound(make_pair(10,INT_MAX));
	cout<<it->first<<" "<<it->second<<endl;

	s.erase(s.find(make_pair(5,3)));
	s.insert(make_pair(5,4));

	for(auto p:s)
	{
		cout<<p.first<<" and "<<p.second<<endl;
	}






	return 0;
}