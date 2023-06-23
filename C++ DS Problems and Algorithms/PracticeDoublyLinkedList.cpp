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

Node *insertAtBegin(Node *head,int x)
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
	{
		return temp;
	}
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
	Node *temp=head;
	head=head->next;
	head->prev=NULL;
	delete temp;
	return head;
}

Node *delEnd(Node *head)
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

Node *insertAtPos(Node *head,int x,int pos)
{
	pos=1;
	Node *temp = new Node(x);
	Node *curr=head;
	for(int i=1;i<pos-1 && curr!=NULL;i++)
		curr=curr->next;

	if(curr==NULL)
		return head;
	else{
	temp->next=curr->next;
	temp->prev=curr;
	curr->next=temp;
	temp->next->prev=temp;
	}
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
	Node *head = NULL;
	head = insertAtBegin(head,50);
	head = insertAtBegin(head,40);
	head = insertAtBegin(head,30);
	head = insertAtEnd(head,60);
	head = insertAtEnd(head,70);
	display(head);
	head = reverse(head);
	//head = insertAtPos(head,100,4);
	//head = delHead(head);
	//head = delEnd(head);
	//head = delEnd(head);
	//head = insertAtPos(head,100,3);
	display(head);
}