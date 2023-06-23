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

int NthNode(Node *head,int n)
{
	if(head==NULL) return NULL;

	Node *first=head;
	for(int i=0;i<n;i++)
	{
		if(first==NULL)
			return NULL;
		first=first->next;
	}

	Node *second=head;
	while(first!=NULL)
	{
		second=second->next;
		first=first->next;
	}
	return second->data;
}

int main()
{
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	head->next->next->next = new Node(40);
	head->next->next->next->next = new Node(50);
	display(head);
	int n = NthNode(head,2);
	cout<<n<<endl;
	// display(head);
	return 0;
}