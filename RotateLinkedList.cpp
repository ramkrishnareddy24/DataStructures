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


Node *rotate(Node *head,int k)
{
	for(int i=0;i<k;i++)
	{
		Node *curr=head;
		while(curr->next->next!=NULL)
		{
			curr=curr->next;
		}
		Node *temp=curr->next;
		curr->next=NULL;
		temp->next=head;
		head=temp;
	}
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


int main()
{
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	head->next->next->next = new Node(40);
	head->next->next->next->next = new Node(50);

	head = rotate(head,2);
	display(head);

	return 0;
}