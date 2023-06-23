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
	if(head==NULL)
	{
		temp->next=temp;
		return temp;
	}
	else
	{
		temp->next=head->next;
		head->next=temp;

		int t = head->data;
		head->data = temp->data;
		temp->data = t;
		return head;
	}
}

//Naive Solution
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
		Node *curr = head;
		while(curr->next!=head)
			curr=curr->next;
		curr->next=temp;
		temp->next=head;
		return head;
	}
}

//Optimised Solution O(1) constant time
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
		int t = head->data;
		head->data=temp->data;
		temp->data=t;
		return temp;
	}
}

//Naive Solution
Node *delHead(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node *curr = head;
	while(curr->next!=head)
		curr=curr->next;
	curr->next=head->next;
	delete head;

	return (curr->next);
}

//Optimized Solution runs in const time O(1)
Node *deleteHead(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	head->data=head->next->data;

	Node *temp = head->next;

	head->next=head->next->next;

	delete temp;

	return head;
}

Node *deleteKthElement(Node *head,int k)
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

	return head;
}

void display(Node *head)
{
	if(head==NULL) return;
	Node *temp = head;
	do
	{
		cout<<temp->data<<"-";
		temp=temp->next;
	}while(temp!=head);

	cout<<endl;
}


int main()
{
	Node *head = NULL;
	head = insertBegin(head,20);
	head = insertBegin(head,10);
	head = insertEnd(head,30);
	// head = insertAtEnd(head,40);
	// head = insertBegin(head,40);
	// head = insertBegin(head,40);
	// display(head);
	// head = delHead(head);
	// head = deleteHead(head);
	// display(head);
	// head = deleteKthElement(head,3);
	display(head);

}

