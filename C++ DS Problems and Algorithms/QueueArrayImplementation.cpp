#include<iostream>
using namespace std;

struct Queue
{
	int size,cap;
	int *arr;
	Queue(int c)
	{
		cap=c;
		size=0;
		arr = new int[cap];
	}

	bool isFull()
	{
		return(size==cap);
	}

	bool isEmpty()
	{
		return(size==0);
	}

	void enqueue(int x)
	{
		if(isFull()) return;

		size++;
		arr[size]=x;
		
	}

	int dequeue()
	{
		if(isEmpty()) return 0;
		for(int i=0;i<size-1;i++)
			arr[i]=arr[i+1];
		size--;
		return arr[0];
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
			return size-1;
	}

	void display()
	{
		if(isEmpty()) return;
		for(int i=0;i<=size-1;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
};

int main()
{
	Queue q(10);
	q.enqueue(10);
	q.enqueue(20);
	cout<<q.dequeue()<<endl;
	q.display();
	return 0;

}