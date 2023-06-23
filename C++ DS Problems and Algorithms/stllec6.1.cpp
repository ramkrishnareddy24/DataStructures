#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> l;

	list<int> l1{1,2,3,10,8,5};

	list<string> l2{"Apple","Guava","Mango","Banana"};
	l2.push_back("PineApple");

	//sort
	l2.sort();
	l2.reverse();
	l2.pop_front();
	cout<<l2.front()<<endl;
	l2.push_front("Kiwi");
	cout<<l2.back()<<endl;
	l2.pop_back();
	cout<<endl;
	for(auto it=l2.begin();it!=l2.end();it++)
	{
		cout<<(*it)<<"->";
	}
	cout<<endl;
	for(string s:l2)
	{
		cout<<s<<"-->";
	}

	return 0;
}