#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next,*prev;
	Node(int x)
	{
		data=x;
		next=prev=NULL;
	}
};

void display(Node *head)
{
	Node *curr=head;
	do
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}while(curr!=NULL);
	cout<<endl;
}

Node *insertBegin(Node *head,int x)
{
	Node *temp=new Node(x);
	if(head==NULL)
	{
		temp->next=temp;
		temp->prev=temp;
		return temp;
	}
	else
	{
		temp->prev=head->prev;
		temp->next=head;
		head->prev->next=temp;
		head->prev=temp;
		return temp;
	}
}

int main()
{
	Node *head = NULL;
	head = insertBegin(head,10);
	head = insertBegin(head,20);
	head = insertBegin(head,30);
	display(head);


}