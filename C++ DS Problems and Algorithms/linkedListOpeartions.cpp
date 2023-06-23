#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

Node *insertAtBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next=head;
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

	return head;
}

Node *delHead(Node *head)
{
	if(head==NULL)
		return NULL;
	
		Node *temp=head->next;

		delete head;
		
	return temp;

}

Node *delTail(Node *head)
{
	if(head==NULL) return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node *curr=head;
	while(curr->next->next!=NULL)
	{
		curr=curr->next;
	}
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
	for(int i=1;i<=pos-2 && curr!=NULL;i++)
		curr=curr->next;

	if(curr==NULL)
		return head;

	temp->next=curr->next;
	curr->next=temp;

	return head;

}

void printList(Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
	Node *head = NULL;
	head = insertAtBegin(head,50);
	head = insertAtBegin(head,40);
	head = insertAtBegin(head,30);
	head = insertAtEnd(head,60);
	head = insertAtEnd(head,70);

	//printList(head);
	//cout<<endl;
	head = delHead(head);
	//cout<<endl;
	//printList(head);
	//cout<<endl;
	//delTail(head);
	//cout<<endl;
	printList(head);
	cout<<endl;
	insertAtPos(head,3,15);

	printList(head);

	return 0;
}

