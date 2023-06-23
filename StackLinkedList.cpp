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
Node *head;

void push(int x)
{
	Node *temp=new Node(x);
	temp->next=head;
	head = temp;
}

int pop()
{
	if(head==NULL)
	{
		cout<<"Stack Empty"<<endl;
		return 0;
	}
	else
	{
		Node *curr=head;
		int res=curr->data;
		head=head->next;
		free(curr);
		return res;
	}
}

void display()
{
	Node *curr=head;
	if(curr==NULL)
	{
		cout<<"Stack Empty"<<endl;
		return;
	}
	
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<endl;
	
}

int main()
{
	push(10);
	push(20);
	push(30);
	display();
	pop();
	display();

	return 0;
}