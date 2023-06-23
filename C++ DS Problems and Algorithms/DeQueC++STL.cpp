#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<int> dq={10,20,30};
	dq.push_front(5);
	dq.push_back(40);

	for(auto x:dq)
		cout<<x<<" ";

	cout<<endl<<dq.front()<<endl;
	cout<<dq.back()<<endl;

	auto it = dq.begin();
	it++;
	dq.insert(it,15);

	for(auto s:dq)
		cout<<s<<" ";
	cout<<endl;

	dq.pop_front();
	dq.pop_back();

	for(auto s:dq)
		cout<<s<<" ";
	cout<<endl;

	it=dq.insert(it,7);
	it=dq.insert(it,2,3);
	it=dq.erase(it+1);
	cout<<(*it)<<endl;
	for(int i=0;i<dq.size();i++)
		cout<<dq[i]<<" ";
}