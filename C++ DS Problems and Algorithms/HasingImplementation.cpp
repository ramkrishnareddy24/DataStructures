#include<bits/stdc++.h>
using namespace std;

//Chaining Implementation
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



// Open Addressing

// //linear Probing
// hash(key,i)=(h(key)+i)%7;

// //Quadrartic Probing
// hash(key,i)=(h(key)+i*i)%7;

// //Double Hashing
// hash(key,i)=(h(key)+i*h2(key))%m;



// Implementation of Open Addressing
// linear probing
struct myHash
{
	int *arr;
	int cap,size;
	myHash(int c)
	{
		cap=c;
		size=0;
		for(int i=0;i<cap;i++)
			arr[i]=-1;
	}

	int hash(int key)
	{
		return (key%cap);
	}

	bool search(int key)
	{
		int h=hash(key);
		int i=h;
		while(arr[i]!=-1)
		{
			if(arr[i]==key)
				return true;

			i=(i+1)%cap;

			if(i==h)
				return false;
		}
		return false;
	}

	bool insert(int key)
	{
		if(size==cap)
			return false;

		int i=hash(key);
		while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
			i=(i+1)%cap;
		
		if(arr[i]==key)
			return false;
		else
		{
			arr[i]=key;
			size++;
			return true;
		}
	}

	bool erase(int key)
	{
		int h=hash(key);
		int i=h;
		while(arr[i]!=-1)
		{
			if(arr[i]==key)
			{
				arr[i]=-2;
				return true;
			}

			i=(i+1)%cap;

			if(i==h)
				return false;
		}
		return false;
	}
};

