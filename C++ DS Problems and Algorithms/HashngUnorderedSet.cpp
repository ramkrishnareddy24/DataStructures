#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	unordered_set<int> s;
	s.insert(10);
	s.insert(5);
	s.insert(20);
	s.insert(30);

	for(auto x:s)
	{
		cout<<x<<" ";
	}cout<<endl;

	cout<<s.size()<<endl;
	//s.clear();
	//cout<<s.size()<<endl;

	for(auto i=s.begin();i!=s.end();i++)
	{
		cout<<(*i)<<" ";
	}

	cout<<endl;
	if(s.find(10)==s.end())
	{
		cout<<"Not Found"<<endl;
	}
	else{
		cout<<"Found :"<<*(s.find(10));
	}
	cout<<endl;

	if(s.count(35))
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not Found";
	}

	cout<<endl<<s.size()<<endl;

	cout<<"Removing:"<<s.erase(10);

	auto it=s.find(5);
	cout<<endl<<"Removing:"<<s.erase(*it);

	cout<<endl<<s.size()<<endl;

	for(auto x:s)
		cout<<x<<" ";



	return 0;

}