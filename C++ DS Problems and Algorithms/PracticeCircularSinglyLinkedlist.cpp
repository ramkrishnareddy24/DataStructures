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

Node *deleteHead(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
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

Node *deleteAtEnd(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
	Node *curr=head;
	while(curr->next->next!=head)
		curr=curr->next;
	curr->next=head;
	delete curr->next->next;

	return head;
}

Node *deleteKthEle(Node *head,int k)
{
	if(head==NULL)
		return NULL;
	if(k==1)
		deleteHead(head);

	Node *curr=head;
	for(int i=0;i<k-2;i++)
	{
		curr=curr->next;
	}

	Node *temp=curr->next;
	curr->next=curr->next->next;

	return head;
}

int lengthOfCLL(Node *head)
{
	int len=0;
	if(head==NULL)
		return NULL;
	Node *curr=head;
	do
	{
		len++;
		curr=curr->next;
	}while(curr!=head);
	return len;
}

int checkIfCLL(Node *head)
{
	if(head==NULL)
		return NULL;
	Node *curr=head;
	while(curr->next!=head)
		curr=curr->next;
	if(curr->next=head)
		cout<<"YeS"<<endl;
	else
		cout<<"No"<<endl;
}

Node *InsertAtPos(Node *head,int x,int pos)
{
	pos=1;
	Node *temp = new Node(x);
	if(head==NULL)
	{
		temp->next=temp;
		return temp;
	}
	
	Node *curr=head;
	for(int i=1;i<=pos-3;i++)
		curr=curr->next;
	/*
	if(curr->next=head)
	{
		head = insertAtEnd(head,x);
	}
	*/

	temp->next=curr->next;
	curr->next=temp;

	return head;
}

void display(Node *head)
{
	Node *curr=head;
	do
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}while(curr!=head);
	cout<<endl;
}
//Cicular Linked List//
int main()
{
	Node *head = NULL;
	head = insertAtBegin(head,100);
	head = insertAtBegin(head,75);
	head = insertAtBegin(head,50);
	head = insertAtEnd(head,125);
	head = insertAtEnd(head,150);
	display(head);
	checkIfCLL(head);
	cout<<lengthOfCLL(head); cout<<endl;
	display(head);
	head = deleteHead(head);
	display(head);
	head = deleteAtEnd(head);
	display(head);
	head = deleteKthEle(head,2);
	display(head);
	//head = InsertAtPos(head,300,2);
	display(head);
	head = insertAtBegin(head,100);
	head = insertAtBegin(head,75);
	head = insertAtBegin(head,50);
	head = insertAtEnd(head,125);
	head = insertAtEnd(head,150);
	display(head);
	//head = InsertAtPos(head,999,5);
	display(head);
}