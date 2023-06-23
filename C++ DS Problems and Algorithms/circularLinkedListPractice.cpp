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

Node *insertBegin(Node *head,int x)
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
	}
	return head;
}

Node *insertEnd(Node *head,int x)
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
	}
	return temp;
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
		head->data=head->next->data;
		Node *temp=head->next;
		head->next=head->next->next;
		delete temp;
		return head;
	}
}

Node *deleteKthNode(Node *head,int k)
{
	if(head==NULL)
		return NULL;
	if(k==1)
		return delHead(head);

	Node *curr=head;
	for(int i=0;i<k-2;i++)
		curr=curr->next;

	Node *temp=curr->next;
	curr->next=curr->next->next;
	delete temp;
	return head;
}

int main()
{
	Node *head = NULL;
	head = insertBegin(head,40);
	head = insertBegin(head,30);
	head = insertBegin(head,20);
	head = insertBegin(head,10);
	head = insertEnd(head,50);
	head = delHead(head);
	head = deleteKthNode(head,2);
	display(head);
	return 0;
}