#include<iostream>
#include"vector.h"
using namespace std;
int main()
{
	vector<char> v;
	v.push_back(71);
	v.push_back(72);
	v.push_back(76);
	v.push_back(80);
	v.pop_back();
	v.push_back(65);
	v.push_back(66);
    
    cout<<v.capacity()<<endl;

	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}

	return 0;
}