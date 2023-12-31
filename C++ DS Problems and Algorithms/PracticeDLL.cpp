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
		prev=next=NULL;
	}
};

Node *insertBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next=head;
	if(head!=NULL)
		head->prev=temp;
	return temp;
}

Node *insertEnd(Node *head,int x)
{
	Node *temp = new Node(x);
	if(head==NULL)
		return temp;

	Node *curr=head;
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;
	temp->prev=curr;
	return head;
}

Node *delHead(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
	else
	{
		Node *temp=head;
		head=head->next;
		head->prev=NULL;
		delete temp;
		return head;
	}
}

Node *delLast(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node *curr=head;
	while(curr->next!=NULL)
		curr=curr->next;

	curr->prev->next=NULL;
	delete curr;

	return head;
}

void display(Node *head)
{
	Node *curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<"-";
		curr=curr->next;
	}cout<<endl;
}

int main()
{
	Node *head = NULL;
	head = insertBegin(head,40);
	head = insertBegin(head,30);
	head = insertBegin(head,20);
	head = insertBegin(head,10);
	head = insertEnd(head,50);
	display(head);
	head = delHead(head);
	display(head);
	head = delLast(head);
	display(head);
}