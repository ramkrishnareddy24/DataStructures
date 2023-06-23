#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

Node *insertAtBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next=head;
	return temp;
}

Node *insertAtEnd(Node *head,int x)
{
	Node *temp = new Node(x);

	if(head==NULL)
		return temp;

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
	else
	{
		Node *temp=head->next;
		free(head);
		return temp;
	}
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
	head = insertAtBegin(head,50);
	head = insertAtBegin(head,40);
	head = insertAtBegin(head,30);
	head = insertAtEnd(head,60);
	head = insertAtEnd(head,70);

	printList(head);

	delHead(head);

	printList(head);

	return 0;
}

/*
Node *delHead(Node *head)
{
if(head==NULL)
return NULL
else
{
	Node *temp = head->next;
	delete head;
	return head;
}
}
*/