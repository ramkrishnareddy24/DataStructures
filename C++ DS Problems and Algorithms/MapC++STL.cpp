#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<int,int> m;
	m.insert({10,200});
	m[5]=100;
	m.insert({3,300});
	for(auto x:m)
		cout<<x.first<<" "<<x.second<<endl;
	cout<<"Size: "<<m.size()<<endl;
	m[20]=400;
	m[40]=500;
	// m.at(30)=600;
	cout<<"Size: "<<m.size()<<endl;

	for(auto it=m.begin();it!=m.end();it++)
		cout<<(*it).first<<" "<<(*it).second<<endl;
	m.clear();
	cout<<m.size()<<endl;
	map<int,string> mp;
	mp.insert({5,"gfg"});
	mp.insert({7,"ide"});
	mp.insert({1,"practice"});
	if(mp.find(5)==mp.end())
		cout<<"Not Found"<<endl;
	else
		cout<<"Found"<<endl;

	for(auto ite=mp.find(5);ite!=mp.end();ite++)
		cout<<"{"<<(*ite).first<<","<<(*ite).second<<"}"<<endl;

	auto iter=mp.lower_bound(4);
	cout<<(*iter).first<<" "<<(*iter).second<<endl;
	auto itera=mp.upper_bound(6);
	cout<<(*itera).first<<" "<<(*itera).second<<endl;
	return 0;
}