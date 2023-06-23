#include<bits/stdc++.h>
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
	temp->next = head;
	return temp;
}

Node *insertAtEnd(Node *head,int x)
{
	Node *temp = new Node(x);
	if(head==NULL)
		return NULL;

	Node *curr = head;
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;

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

	Node *curr = head->next;
	delete head;
	return curr;
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
		curr=curr->next;
	delete curr->next;
	curr->next=NULL;
	return head;
}

int search(Node *head,int x)
{
	int pos=1;
	Node *curr=head;
	while(curr!=NULL)
	{
		if(curr->data==x)
			return pos;
		else
		{
			curr=curr->next;
			pos++;
		}
	}
	return -1;
}

Node *insertAtPos(Node *head,int pos,int x)
{
	pos=1;
	Node *temp = new Node(x);
	Node *curr=head;
	if(head==NULL)
	{
		temp->next=head;
		return temp;
	}

	for(int i=1;i<pos-2 && curr!=NULL;i++)
		curr=curr->next;

	if(curr==NULL)
		return head;

	temp->next=curr->next;
	curr->next=temp;
	return head;
}

Node *reverse(Node *head)
{
	Node *curr=head;
	Node *prev=NULL;
	while(curr!=NULL)
	{
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

void display(Node *head)
{
	Node *curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

int main()
{
	Node *head = NULL;
	head = insertAtBegin(head,1);
	head = insertAtBegin(head,2);
	display(head);

	return 0;
}