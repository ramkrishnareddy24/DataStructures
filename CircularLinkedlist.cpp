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

void display(Node *head)
{
	if(head==NULL) return;
	Node *curr=head;
	do
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}while(curr!=head);

	cout<<endl;
}

Node *insertBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	
	if(head==NULL)
	{
		temp->next=temp;
		return temp;
	}
	else
	{
		temp->next=head->next;
		head->next=temp;

		int t = head->data;
		head->data = temp->data;
		temp->data = t;

		return head;
	}
}

Node *insertAtEnd(Node *head,int x)
{
	Node *temp = new Node(x);

	if(head==NULL)
	{
		temp->next=temp;
		return temp;
	}
	else
	{
		temp->next=head->next;
		head->next=temp;

		int t = head->data;
		head->data = temp->data;
		temp->data = t;

		return temp;
	}
}

Node *insertEnd(Node *head,int x)
{
	Node *temp = new Node(x);
	if(head==NULL)
	{
		temp->next=temp;
		return temp;
	}
	else
	{
		Node *curr=head;
		while(curr->next!=head)
			curr=curr->next;

		curr->next=temp;
		temp->next=head;

		return head;
	}
}

Node *deleteHead(Node *head)
{
	if(head==NULL) return NULL;
	if(head->next=head){
		delete head;
		return NULL;
	}

	Node *curr=head;
	while(curr->next!=head)
		curr=curr->next;

	curr->next=head->next;
	delete head;

	return curr->next;
}

int main()
{
	Node *head = NULL;
	head = insertEnd(head,50);
	head = insertBegin(head,30);
	head = insertAtEnd(head,60);
	head = insertBegin(head,70);
	display(head);

	return 0;
}