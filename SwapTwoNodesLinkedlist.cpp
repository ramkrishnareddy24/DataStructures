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

void swapNodes(Node *head,int x,int y)
{
	if(x==y)
		return;

	Node *prevX=NULL,*currX=head;
	while(currX && currX->data!=x)
	{
		prevX=currX;
		currX=currX->next;
	}

	Node *prevY=NULL,*currY=head;
	while(currY && currY->data!=y)
	{
		prevY=currY;
		currY=currY->next;
	}

	if(currX==NULL || currY==NULL)
		return;

	if(prevX!=NULL)
		prevX->next=currY;
	else
		head=currY;

	if(prevY!=NULL)
		prevY->next=currX;
	else
		head=currX;

	// Node *temp=currY->next;
	// currY->next=currX->next;
	// currX->next=temp;
	swap(currX->next,currY->next);
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

	swapNodes(head,20,40);
	display(head);
}