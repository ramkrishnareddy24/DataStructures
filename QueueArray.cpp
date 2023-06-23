#include<bits/stdc++.h>
using namespace std;
	
class Queue
{
public:
	int cap;
	int size;
	int *arr;
	Queue(int c)
	{
		cap=c;
		size=0;
		arr = new int[c];
	}

	int isFULL()
	{
		return (size==cap);
	}

	int isEmpty()
	{
		return (size==0);
	}

	void enqueue(int x)
	{
		if(isFULL()){
			cout<<"Queue full"<<endl;
			return;
		}
		
		arr[size]=x;
		size++;
	}

	int dequeue()
	{
		if(isEmpty())
		{
			cout<<"Queue Empty"<<endl;
			return 0;
		}
		for(int i=0;i<size;i++)
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
		if(isFULL())
			return -1;
		else
			return size-1;
	}

	void display()
	{
		if(isEmpty())
		{
			cout<<"Queue Empty"<<endl;
			return;
		}
		for(int i=0;i<size-1;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	
};

// int main()
// {
// 	Queue q(10);
// 	q.enqueue(10);
// 	q.enqueue(20);
// 	q.enqueue(30);
// 	q.display();
// 	q.dequeue();
// 	q.display();

// 	return 0;
// }

