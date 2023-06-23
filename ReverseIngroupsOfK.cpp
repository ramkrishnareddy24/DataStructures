#include<bits/stdc++.h>
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

Node *reverseInGroupsOfK(Node *head,int k)
{
	Node *curr=head;
	Node *prev=NULL;
	Node *next=NULL;
	int count=0;

	while(curr!=NULL && count<k)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;

		count++;
	}
	if(next!=NULL)
	{
		Node *rest_head=reverseInGroupsOfK(head,k);
		head->next=rest_head;
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
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	head->next->next->next = new Node(40);
	head->next->next->next->next = new Node(50);

	head = reverseInGroupsOfK(head,2);
	display(head);


}