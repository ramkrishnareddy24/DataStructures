#include<iostream>
#include<algorithm>
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

Node *insertEnd(Node *head,int x)
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

//Naive Solution
void pairWiseSwap(Node *head)
{
	Node *curr=head;
	while(curr!=NULL && curr->next!=NULL)
	{
		swap(curr->data,curr->next->data);
		curr=curr->next->next;
	}
}

//Efficient Solution
Node *PairWiseSwap(Node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
	Node *curr=head->next->next;
	Node *prev=head;
	head=head->next;
	head->next=prev;

	while(curr!=NULL && curr->next!=NULL)
	{
		prev->next=curr->next;
		prev=curr;
		Node *next=curr->next->next;
		curr->next->next=curr;
		curr=next;
	}
	prev->next=curr;
	return head;
}

int main()
{
	Node *head=NULL;
	head = insertEnd(head,1);
	head = insertEnd(head,2);
	head = insertEnd(head,3);
	head = insertEnd(head,4);
	head = insertEnd(head,5);
	// display(head);
	pairWiseSwap(head);
	display(head);
	// display(head);
	PairWiseSwap(head);
	display(head);
	return 0;
}