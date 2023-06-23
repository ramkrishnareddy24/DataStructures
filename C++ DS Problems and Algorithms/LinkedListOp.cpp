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

Node *insertBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next=head;
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

	return head;
}

Node *delHead(Node *head)
{
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		Node *temp=head->next;
		delete head;
		return temp;
	}
}

Node *DelEnd(Node *head)
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

Node *insertAtPos(Node *head,int pos,int x)
{
	Node *temp = new Node(x);

	if(pos==1)
	{
		temp->next=head;
		return temp;
	}

	Node *curr=head;
	for(int i=1;i<=pos-2&&curr!=NULL;i++)
		curr=curr->next;

	if(curr==NULL)
		return head;

	temp->next=curr->next;
	curr->next=temp;

	return head;
}

Node *sortedInsert(Node *head,int x)
{
	Node *temp = new Node(x);

	if(head==NULL)
		return temp;

	if(head->data>x)
	{
		temp->next=head;
		return temp;
	}

	Node *curr=head;
	while(curr->next!=NULL && curr->next->data<x)
		curr=curr->next;

	temp->next=curr->next;
	curr->next=temp;

	return head;
}

void printMiddle(Node *head)
{
	Node *slow=head,*fast=head;
	if(head==NULL)
		return;

	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}

	cout<<(slow->data);
	cout<<endl;
}

void printNthEnd(Node *head,int n)
{
	if(head==NULL) return;

	Node *first=head;
	for(int i=0;i<n;i++)
	{
		if(first==NULL) 
			return;
		first=first->next;
	}

	Node *second=head;
	while(first!=NULL)
	{
		second=second->next;
		first=first->next;
	}

	cout<<second->data;

	cout<<endl;
}

void print(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

Node *ReverseLL(Node *head)
{
	Node *curr=head;
	Node *prev=NULL;
	while(curr!=NULL)
	{
		Node *next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

Node *recRevL(Node *head)
{
	if(head==NULL || head->next==NULL) 
		return head;


	Node *restHead=recRevL(head->next);
	Node *restTail=head->next;
	restTail->next=head;
	head->next=NULL;

	return restHead;

}

int main()
{
	Node *head = NULL;
	head = insertBegin(head,30);
	head = insertBegin(head,20);
	head = insertBegin(head,10);
	// head = recRevL(head);
	// print(head);
	// print(head);
	head = insertEnd(head,40);
	head = insertEnd(head,50);
	print(head);
	head = ReverseLL(head);
	print(head);
	// head = delHead(head);
	// print(head);
	// head = DelEnd(head);
	// printMiddle(head);
	// print(head);
	// head = insertAtPos(head,2,25);
	// print(head);
	// head = sortedInsert(head,35);
	// head = sortedInsert(head,60);
	// head = sortedInsert(head,15);
	//print(head);
	//printMiddle(head);
	// printNthEnd(head,2);
	// ReverseLL(head);
	// print(head);
	// head = recRevL(head);
	// print(head);
	// head = insertBegin(head,100);
	// print(head);
	
}