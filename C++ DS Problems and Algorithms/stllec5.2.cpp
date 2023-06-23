#include<iostream>
#include<vector>
using namespace std;


int main()
{
	vector<int> d{1,2,3,10,4};

	d.push_back(16);

	d.pop_back();

	d.insert(d.begin()+3,4,100);

	d.erase(d.begin()+2,d.begin()+5);

	cout<<d.size()<<endl;
	cout<<d.capacity()<<endl;
    
    d.clear();


	for(int x:d)
		cout<<x<<" ";
	cout<<endl;
	cout<<d.front()<<endl;
	cout<<d.back()<<endl;

}