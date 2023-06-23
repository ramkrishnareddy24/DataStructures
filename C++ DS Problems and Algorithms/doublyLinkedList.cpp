#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *prev;
	Node *next;
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

Node *insertAtEnd(Node *head,int x)
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

Node *delLastNode(Node *head)
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

Node *reverseDLL(Node *head)
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
	// return prev;
	if(prev!=NULL)
		head=prev->prev;
}




void display(Node *head)
{
	Node *curr = head;
	while(curr!=NULL)
	{
		cout<<curr->data<<"-";
		curr=curr->next;
	}
	cout<<endl;
}

int main()
{
	Node *head = NULL;
	head = insertBegin(head,50);
	head = insertBegin(head,30);
	head = insertAtEnd(head,60);
	display(head);
	head = reverseDLL(head);
	display(head);

	// head = delHead(head);
	// display(head);
	// head = delLastNode(head);
	// display(head);
}