#include<iostream>
using namespace std;

struct Queue
{
	int *arr;
	int cap;
	int size;
	Queue(int c)
	{
		cap=c;
		size=0;
		arr = new int[cap];
	}

	bool isEmpty()
	{
		return(size==0);
	}

	bool isFull()
	{
		return(size==cap);
	}

	int getFront()
	{
		if(isEmpty())
			return -1;
		else
			return 0;
	}

	int getRear()
	{
		if(isEmpty())
			return -1;
		else
			return(size-1);
	}

	void enqueue(int x)
	{
		if(isFull())
			return;
		arr[size]=x;
		size++;
	}

	void dequeue()
	{
		if(isEmpty())
			return;
		
		for(int i=0;i<size-1;i++)
			arr[i]=arr[i+1];
		size--;
	}

	void display()
	{
		if(isEmpty())
			return;
		for(int i=0;i<size-1;i++)
			cout<<arr[i]<<" ";
	}
};

int main()
{
	Queue q(10);
	q.enqueue(10);
	q.enqueue(20);
	q.display();
	q.dequeue();
	q.display();
	return 0;
}

