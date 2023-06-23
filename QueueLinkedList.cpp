#include<bits/stdc++.h>
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

	Queue()
	{
		front=NULL;
		rear=NULL;
	}

	void enqueue(int x)
	{
		Node *temp = new Node(x);

		if(front==NULL)
		{
			front=rear=temp;
			return;
		}

		rear->next=temp;
		rear=temp;
		return;
	}

	void dequeue()
	{
		if(front==NULL)
			return;

		Node *curr=front;
		front=front->next;

		if(front==NULL)
			rear=NULL;

		delete curr;
	}

	void display()
	{
		Node *curr=front;
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<endl;
	}

};

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.display();
	q.dequeue();
	q.display();

	return 0;
}