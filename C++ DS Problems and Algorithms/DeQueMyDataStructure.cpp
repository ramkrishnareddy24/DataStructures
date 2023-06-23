//Design a data structure that supports following
//operations in O(1) time complexity.

#include<iostream>
#include<deque>
using namespace std;

struct MyDataStructure
{
	deque<int> dq;

	void insertMin(int x)
	{
		dq.push_front(x);
	}	

	void insertMax(int x)
	{
		dq.push_back(x);
	}

	void getMin()
	{
		cout<<dq.front()<<endl;
	}

	void getMax()
	{
		cout<<dq.back()<<endl;

	}

	void extractMin()
	{
		dq.pop_front();
	}

	void extractMax()
	{
		dq.pop_back();
	}
};

int main()
{
	MyDataStructure m;
	m.insertMin(5);
	m.insertMax(10);
	m.insertMin(3);
	m.insertMax(15);
	m.insertMin(2);
	m.getMin();
	m.getMax();
	m.insertMin(1);
	m.getMin();
	m.insertMax(20);
	m.getMax();
}