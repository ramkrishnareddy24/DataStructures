#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	unordered_set<int> us;
	us.insert(10);
	us.insert(20);
	us.insert(15);
	us.insert(5);
	for(auto it=us.begin();it!=us.end();it++)
		cout<<(*it)<<" ";
	cout<<" "<<us.size()<<endl;
	if(us.find(15)==us.end())
		cout<<"Not Found"<<endl;
	else
		cout<<"Found  "<<*(us.find(15));

	if(us.count(15))
		cout<<"Found"<<endl;
	else
		cout<<"Not Found "; 

	auto it=us.find(10);
	us.erase(it);
	cout<<us.size()<<" ";


	us.erase(us.begin(),us.end());
	cout<<us.size()<<" ";
}