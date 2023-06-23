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

Node *insertBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	if(head==NULL)
		return temp;
	else
	{
		temp->next=head;
		head->prev=temp;
		return temp;
	}
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
	return prev;
}

Node *deleteHead(Node *head)
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

Node *deleteTail(Node *head)
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



int main()
{
	Node *head=NULL;
	head = insertBegin(head,10);
	head = insertBegin(head,20);
	// display(head);
	head = insertBegin(head,30);
	head = insertEnd(head,40);
	head = insertEnd(head,50);
	display(head);
	// head = reverse(head);
	display(head);
	head = deleteHead(head);
	display(head);
	head = deleteTail(head);
	display(head);

	return 0;
}