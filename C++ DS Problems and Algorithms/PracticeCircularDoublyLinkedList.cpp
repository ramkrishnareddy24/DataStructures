#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *prev;
	Node(int x)
	{
		data=x;
		next=prev=NULL;
	}
};

Node *insertBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	if(head==NULL)
	{
		temp->next=temp;
		temp->prev=temp;
		return temp;
	}

	temp->prev=head->prev;
	temp->next=head;
	head->prev->next=temp;
	head->prev=temp;
	return temp;
}

Node *insertEnd(Node *head,int x)
{
	Node *temp = new Node(x);
	if(head==NULL)
	{
		temp->next=temp;
		temp->prev=temp;
		return temp;
	}

	temp->prev=head->prev;
	temp->next=head;
	head->prev->next=temp;
	head->prev=temp;
	return head;
}

void display(Node *head)
{
	Node *curr=head;
	do
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}while(curr!=head);
	cout<<endl;
}

int main()
{
	Node *head=NULL;
	head = insertBegin(head,30);
	head = insertBegin(head,20);
	head = insertBegin(head,10);
	display(head);
	head = insertEnd(head,40);
	display(head);

	return 0;
}