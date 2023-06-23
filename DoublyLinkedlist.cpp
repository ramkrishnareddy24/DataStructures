#include<bits/stdc++.h>
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
	Node *temp=new Node(x);
	temp->next=head;
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

	Node *curr=head->next;
	delete head;
	return curr;
}

Node *delTail(Node *head)
{
	if(head==NULL)
		return NULL;

	Node *curr=head;
	while(curr->next->next!=NULL)
		curr=curr->next;

	delete curr->next;
	curr->next=NULL;
	return head;
}

Node *insertAtPos(Node *head,int x,int pos)
{
	Node *temp = new Node(x);

	if(pos==1)
	{
		temp->next=head;
		head->prev=temp;
		return temp;
	}

	Node *curr=head;
	for(int i=0; i<pos-2 && curr->next!=NULL; i++)
		curr=curr->next;

	temp->next=curr->next;
	curr->next->prev=temp;;
	curr->next=temp;
	temp->prev=curr;

	return head;
}

Node *reverse(Node *head)
{
	if(head==NULL || head->next==NULL)
		return head;

	Node *curr=head;
	Node *prev=NULL;

	while(curr!=NULL)
	{
		prev=curr->prev;
		curr->prev=curr->next;
		curr->next=prev;

		curr=curr->prev;
	}
	if(prev!=NULL)
		head = prev->prev;
}

void display(Node *head)
{
	Node *curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

int main()
{
	Node *head = new Node(30);
	head = insertBegin(head,20);
	display(head);
	head = insertEnd(head,40);
	display(head);
	head = delHead(head);
	display(head);
	head = delTail(head);
	display(head);
	head = insertEnd(head,40);
	head = insertEnd(head,50);
	head = insertEnd(head,60);
	display(head);
	head = insertAtPos(head,45,3);
	display(head);
	head = insertAtPos(head,100,3);
	display(head);
	// head = reverse(head);
	display(head);

	return 0;
}