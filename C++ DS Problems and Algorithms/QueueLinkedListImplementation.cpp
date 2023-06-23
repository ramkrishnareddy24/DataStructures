#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int x)
	{
		data=x;
		next=NULL;
	}
};

struct Queue
{
	Node *front,*rear;
	int size;

	Queue()
	{
		front=NULL;
		rear=NULL;
		size=0;
	}

	void enquque(int x)
	{
		Node *temp = new Node(x);
		size++;
		if(front==NULL)
		{
			front=rear=temp;
			return;
		}

		rear->next=temp;
		rear=temp;
	}

	void dequeue()
	{
		if(front==NULL)
			return;
		size--;

		Node *temp=front;
		front=front->next;
		if(front==NULL)
			rear=NULL;
		delete temp;
	}

	void display()
	{
		Node *curr=front;
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->next;
		}cout<<endl;
	}
};

int main()
{
	Queue q;
	q.enquque(10);
	q.enquque(20);
	q.enquque(30);
	q.dequeue();
	q.display();
}