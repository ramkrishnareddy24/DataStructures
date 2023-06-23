#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> s;
	s.insert(10);
	s.insert(2);
	s.insert(5);

	for(auto it=s.begin();it!=s.end();it++)
		cout<<(*it)<<" ";
	cout<<endl;
	for(auto it=s.rbegin();it!=s.rend();it++)
		cout<<(*it)<<" ";
	cout<<endl;
	s.insert(10);
	s.insert(5);
	for(auto it=s.begin();it!=s.end();it++)
		cout<<(*it)<<" ";
	cout<<endl;

	auto it=s.find(5);

	if(it==s.end())
		cout<<"Not Found"<<endl;
	else
		cout<<"Found"<<endl;

	// while(it!=s.end())
	// 	cout<<(*it)<<" ";

	// s.clear();
	cout<<s.size()<<endl;

	s.erase(it,s.end());
	for(auto it=s.begin();it!=s.end();it++)
		cout<<(*it)<<" ";
	cout<<endl;
	s.clear();

	s.insert(10);
	s.insert(5);
	s.insert(20);
	auto ite = s.upper_bound(5);
	if(ite!=s.end())
		cout<<"UpperBound: "<<(*ite)<<" ";
	else
		cout<<"Given element is greater than the Largest";

	return 0;
}