#include<iostream>
using namespace std;

struct Queue
{
	int cap;
	int front,size;
	int *arr;
	Queue(int c)
	{
		cap=c;
		size=0;
		cap=0;
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

	int getFront()
	{
		if(isEmpty())
			return -1;
		else
			return front;
	}

	int getRear()
	{
		if(isEmpty())
			return -1;
		else
			return((front+size-1)%cap);
	}

	void enquque(int x)
	{
		if(isFull()) return;
		int rear=getRear();
		rear=(rear+1)%cap;
		size++;
	}

	void dequque()
	{
		if(isEmpty()) return;
		front=(front+1)%cap;
		size--;
	}

	void display()
	{
		int front = getFront(),rear=getRear();
		if (front == -1)
    	{
        cout<<"Queue is Empty";
        return;
    	}
    	cout<<"Queue Elements:"<<endl;
    	if (rear >= front)
    	{
        for (int i = front; i <= rear; i++)
    	        cout<<arr[i]<<" ";
    	}
    	else
    	{
        for (int i = front; i < size; i++)
            cout<<arr[i]<<" ";
 
        for (int i = 0; i <= rear; i++)
            cout<<arr[i]<<" ";
   		}
	}
};

int main()
{
	Queue q(3);
	q.enquque(1);
	q.enquque(2);
	q.enquque(3);
	q.display();
	return 0;
}