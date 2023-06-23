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

Node *inserAtBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next=head;
	return temp;	
}

Node *deletion(Node *head,int pos)
{
	if(head==NULL)
		return NULL;
	if(pos==1)
	{
		delete head;
		return NULL;
	}

	Node *curr=head;
	for(int i=1;i<=pos-1 && curr!=NULL;i++)
		curr=curr->next;

	curr->next=curr->next->next;
	delete curr->next;

	return head;
}

void print(Node *head)
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
	head = inserAtBegin(head,10);
	head = inserAtBegin(head,30);
	head = inserAtBegin(head,50);
	//print(head);
	head = deletion(head,1);
	print(head);

	return 0;
}
