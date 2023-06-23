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
	Node *temp=new Node(x);
	temp->next=head;
	return temp;
}

Node *insertAtEnd(Node *head,int x)
{
	Node *temp = new Node(x);

	if(head==NULL)
		return NULL;

	Node *curr=head;
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;

	return head;
}

Node *delHead(Node *head)
{
	if(head==NULL)
		return NULL;
	Node *temp=head->next;
	delete head;

	return temp;
}

Node *delTail(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node *curr=head;
	while(curr->next->next!=NULL)
	{
		curr=curr->next;
	}
	delete curr->next;
	curr->next=NULL;

	return head;
}

void printList(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main()
{
	Node *head = NULL;
	head = insertAtBegin(head,10);
	head = insertAtBegin(head,5);
	head = insertAtEnd(head,15);

	printList(head);
	head = delHead(head);
	cout<<endl;
	printList(head);
	cout<<endl;
	delTail(head);
	printList(head);

	return 0;
}