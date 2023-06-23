#include<bits/stdc++.h>
using namespace std;

struct MyHash
{
	int BUCKET;
	list<int> *table;
	MyHash(int b)
	{
		BUCKET=b;
		table=new list<int>[BUCKET];
	}

	int hash(int key)
	{
		return (key%BUCKET);
	}

	bool search(int key)
	{
		int i=hash(key);
		for(auto x:table[i])
			if(x==key)
				return true;
		return false;
	}

	void insert(int key)
	{
		int i=hash(key);
		table[i].push_back(key);
	}

	void remove(int key)
	{
		int i=hash(key);
		table[i].remove(key);
	}
};