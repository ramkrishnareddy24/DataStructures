#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> a;
	vector<int> b(5,10);
	vector<int> c{1,2,3,4,5};
	vector<int> d(b.begin(),b.end());

	for(int i=0;i<b.size();i++)
	{
		 cout<<b[i]<<",";
	}

	for(auto it=b.begin();it!=b.end();it++)
	{
		cout<<(*it)<<"*"; 
	}

	//for Each loop
	for(auto x:d)
	{
		cout<<x<<"+";
	}
	cout<<endl;
	vector<int> v;
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		int no;
		cin>>no;
		v.push_back(no);
	}

	for(int x:v)
	{
		cout<<x<<"    ";
	}
    cout<<endl;
	//memory level
	cout<<v.size()<<endl;
	cout<<v.max_size()<<endl;
	cout<<v.capacity()<<endl;

}
