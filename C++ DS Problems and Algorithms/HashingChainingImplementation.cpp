#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Myhash
{
	int BUCKET;
	list<int> *table;
	Myhash(int b)
	{ 
		BUCKET=b; 
		table = new list<int> [BUCKET]; 
	}

	void insert(int key)
	{
		int i=hash(key);
		table[i].push_back(key);
	}
	void delete(int key)
	{
		int i=hash(key);
		table[i].remove(key);
	}
	bool search(int key)
	{
		int i=hash(key);
		for(auto x:table[i])
			if(x==key)
				return true;
			return false;
	}
	int hash(int key) { return key%BUCKET; }


};
