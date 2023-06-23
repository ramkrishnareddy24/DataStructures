//Circular Linked List Operations.......

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

Node *insertAtBegin(Node *head,int x)
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
		int t=head->data;
		head->data=temp->data;
		temp->data=t;
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
		int t=head->data;
		head->data=temp->data;
		temp->data=t;
		return temp;
	}
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
	
	Node *curr = head;
	while(curr->next!=head)
		curr=curr->next;
	curr->next=head->next;
	delete head;

	return curr->next;
}

Node *delKthElement(Node *head,int k)
{
	if(head==NULL)
		return head;
	if(k==1)
	{
		return delHead(head);
	}

	Node *curr=head;
	for(int i=0;i<k-2;i++)\
		curr=curr->next;

	Node *temp=curr->next;
	curr->next=curr->next->next;

	delete temp;

	return head;
}

void display(Node *head)
{
	if(head==NULL)
		return;
	Node *temp = head;
	do
	{
		cout<<temp->data<<"-";
		temp=temp->next;
	}while(temp!=head);
	cout<<endl;
}

int main()
{
	Node *head = NULL;
	head = insertAtBegin(head,50);
	head = insertAtBegin(head,40);
	head = insertAtBegin(head,30);
	head = insertAtEnd(head,60);
	head = insertAtEnd(head,70);
	display(head);
	head = delHead(head);
	display(head);
	head = delKthElement(head,2);
	display(head);
}