#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
	unordered_map<string,int> m;
	m["gfg"]=20;
	m["ide"]=30;
	m.insert({"code",40});

	for(auto x:m)
	{
		cout<<x.first<<" : "<<x.second<<endl;
	}cout<<endl;


	if(m.find("ide")!=m.end())
		cout<<"Found"<<endl;
	else
		cout<<"Not Found"<<endl;

	for(auto it=m.begin();it!=m.end();it++)
	{
		cout<<(it->first)<<" "<<(it->second)<<endl;
	}

	cout<<m.size()<<endl;
	m.erase("ide");
	cout<<m.size()<<endl;
	m.erase(m.begin(),m.end());
	cout<<m.size()<<endl;




	return 0;
}