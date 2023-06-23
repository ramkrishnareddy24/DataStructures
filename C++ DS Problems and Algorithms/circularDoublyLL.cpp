//Circular Doubly Linked List Operations
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

Node *insertAtEnd(Node *head,int x)
{
	Node *temp = new Node(x);
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

		return head;
	}

}

void display(Node *head)
{
	Node *curr=head;
	do
	{
		cout<<curr->data<<"->";
		curr=curr->next;
	}while(curr!=head);
	cout<<endl;
}

int main()
{
	Node *head = NULL;
	int x,y,choice;
	while(1)
	{
		cout<<"1.insertAtBegin\n2.inserAtEnd\n3.display"<<endl;
		cout<<"Enter Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Insert At Begin:"; cin>>x;
			head = insertBegin(head,x);
			break;
			case 2:cout<<"Insert At End:"; cin>>y;
			head = insertAtEnd(head,y);
			break;
			case 3: display(head);
			break;
			case 4: exit(0);
			break;
			default : cout<<"Invalid"<<endl;

		}
	}
}