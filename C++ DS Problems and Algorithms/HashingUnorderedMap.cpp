#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	unordered_map<string,int> um;
	um["gfg"]=20;
	um["ide"]=30;
	um.insert({"course",40});
	for(auto x:um)
		cout<<x.first<<" "<<x.second<<endl;

	if(um.find("ide")!=um.end())
		cout<<"Found  ";
	else
		cout<<"Not Found";

	for(auto it=um.begin();it!=um.end();it++)
		cout<<(it->first)<<" "<<(it->second)<<endl;

	auto it=um.find("ide");
	if(it!=um.end())
		cout<<(it->second)<<endl;

	cout<<um.size()<<" ";
	um.erase("ide");
	um.erase(um.begin());
	cout<<um.size()<<endl;
}