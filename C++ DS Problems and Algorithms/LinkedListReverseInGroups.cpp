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

void display(Node *head)
{
	Node *curr=head;
	while(curr!=NULL)
	{
		cout<<(curr->data)<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

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

//Recursive Solution
Node *ReverseInGroupsK(Node *head,int k)
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
		Node *rest_head=ReverseInGroupsK(next,k);
		head->next=rest_head;
	}
	return prev;
}

//Iterative Solution
Node *reverseInGroupsK(Node *head,int k)
{
	Node *curr=head;
	Node *prevFirst=NULL;
	bool isFirstPass=true;
	while(curr!=NULL)
	{
		Node *first=curr,*prev=NULL;
		int count=0;
		while(curr!=NULL && count<k)
		{
			Node *next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			count++;
		}
		if(isFirstPass)
		{
			head=prev;
			isFirstPass=false;
		}
		else
		{
			prevFirst->next=prev;
		}
		prevFirst=first;
	}
	return head;
}

int main()
{
	Node *head = NULL;
	head=insertEnd(head,10);
	head=insertEnd(head,20);
	head=insertEnd(head,30);
	head=insertEnd(head,40);
	head=insertEnd(head,50);
	head=insertEnd(head,60);
	head=insertEnd(head,70);
	display(head);
	head = ReverseInGroupsK(head,3);
	display(head);
	head = reverseInGroupsK(head,3);
	display(head);
	return 0;
}