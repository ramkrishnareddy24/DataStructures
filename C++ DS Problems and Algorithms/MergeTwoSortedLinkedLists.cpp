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

//Efficient Solution
Node *sortedMerge(Node *a,Node *b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;

	Node *head=NULL,*tail=NULL;
	if(a->data<=b->data)
	{
		head=tail=a;
		a=a->next;
	}
	else
	{
		head=tail=b;
		b=b->next;
	}

	while(a!=NULL && b!=NULL)
	{
		if(a->data<=b->data)
		{
			tail->next=a;
			tail=a;
			a=a->next;
		}
		else
		{
			tail->next=b;
			tail=b;
			b=b->next;
		}
	}

	if(a==NULL)
		tail->next=b;
	else
		tail->next=a;

	return head;
}

int main()
{
	Node *head1=NULL;
	head1 = insertEnd(head1,10);
	head1 = insertEnd(head1,20);
	head1 = insertEnd(head1,30);
	head1 = insertEnd(head1,40);
	display(head1);

	Node *head2=NULL;
	head2 = insertEnd(head2,5);
	head2 = insertEnd(head2,15);
	head2 = insertEnd(head2,17);
	head2 = insertEnd(head2,18);
	head2 = insertEnd(head2,35);
	display(head2);

	Node *head=NULL;
	head = sortedMerge(head1,head2);
	display(head);

	return 0;
}