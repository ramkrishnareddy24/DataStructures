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

//Iterative Display
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

//recursive Display
void recDisplay(Node *head)
{
	if(head==NULL)
		return;
	cout<<(head->data)<<" ";
	recDisplay(head->next);
}

//Iterative
int search(Node *head,int x)
{
	int pos=1;
	Node *curr=head;

	while(curr!=NULL)
	{
		if(curr->data==x)
			return pos;
		else
		{
			pos++;
			curr=curr->next;
		}
	}
	return -1;
}

//Recursive
int RecSearch(Node *head,int x)
{
	if(head==NULL)
		return -1;

	if(head->data==x)
		return 1;
	else
	{
		int res=RecSearch(head->next,x);
		if(res==-1)
			return -1;
		else
			return (res+1);
	}
}

Node *insertBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next=head;
	return temp;
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

Node *delHead(Node *head)
{
	if(head==NULL)
		return NULL;
	else
	{
		Node *temp=head->next;
		delete head;
		return temp;
	}
}

Node *delTail(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node *curr=head;
	while(curr->next->next!=NULL)
		curr=curr->next;
	delete (curr->next);
	curr->next=NULL;
	return head;
}

Node *insertAtPos(Node *head,int pos,int x)
{
	Node *temp = new Node(x);
	Node *curr = head;
	if(pos==1)
	{
		temp->next=head;
		return temp;
	}

	for(int i=0;i<pos-2;i++)
		curr=curr->next;
	//if position is beyond size limit
	if(curr==NULL)
		return NULL;
	temp->next=curr->next;
	curr->next=temp;
	return head;
}

Node *sortedInsert(Node *head,int x)
{
	Node *temp = new Node(x);
	Node *curr=head;

	if(head==NULL)
		return temp;
	if(x<head->data)
	{
		temp->next=head;
		return temp;
	}

	while(curr->next!=NULL && curr->next->data<x)
		curr=curr->next;
	temp->next=curr->next;
	curr->next=temp;
	return head;
}

//Efficient Solution
int middleOfList(Node *head)
{
	if(head==NULL)
		return NULL;

	Node *slow=head;
	Node *fast=head;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return (slow->data); 
}

//Method-1
void printNthFromEnd(Node *head,int n)
{
	int len=0;
	for(Node *curr=head;curr!=NULL;curr=curr->next)
		len++;
	if(len<n)
		return;
	Node *curr=head;
	for(int i=1;i<(len-n+1);i++)
		curr=curr->next;
	cout<<(curr->data)<<" "; 
}

//Method-2 :Two-Pointer-Approach
void PrintNthFromEnd(Node *head,int n)
{
	if(head==NULL)
		return;
	Node *first=head;
	for(int i=0;i<n;i++)
	{
		if(first==NULL)
			return;
		first=first->next;
	}

	Node *second=head;
	while(first!=NULL)
	{
		first=first->next;
		second=second->next;
	}
	cout<<second->data<<" ";
}

//Iterative
Node *reverse(Node *head)
{
	Node *curr=head;
	Node *prev=NULL;

	while(curr!=NULL)
	{
		Node *next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

// recursive Reverse :Method-1
Node *recReverse(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
		return head;

	Node *rest_head=recReverse(head->next);
	Node *rest_tail=head->next;
	rest_tail->next=head;
	head->next=NULL;
	return rest_head;
}

// recursive Reverse :Method-2 :Efficiently Working
Node *RecReverse(Node *curr,Node *prev)
{
	if(curr==NULL)
		return prev;
	Node *next=curr->next;
	curr->next=prev;
	return RecReverse(next,curr);
}

void removeDups(Node *head)
{
	if(head==NULL)
		return;
	Node *curr=head;
	while(curr!=NULL && curr->next!=NULL)
	{
		if(curr->data==curr->next->data)
		{
			Node *temp=curr->next;
			curr->next=curr->next->next;
			delete temp;
		}
		else
		{
			curr=curr->next;
		}
	}
}

int main()
{
	// Node *head = new Node(10);
	// Node *temp1 = new Node(20);
	// Node *temp2 = new Node(30);
	// head->next=temp1;
	// temp1->next=temp2;
	// Node *head = new Node(10);
	// head->next = new Node(20);
	// head->next->next = new Node(30);
	// head->next->next->next = new Node(40);

	Node *head=NULL;
	head=insertBegin(head,40);
	head=insertBegin(head,30);
	head=insertBegin(head,20);
	head=insertBegin(head,10);
	head=insertEnd(head,50);
	head=insertEnd(head,60);
	head=delHead(head);
	head=delTail(head);
	head=insertAtPos(head,3,35);
	display(head);
	recDisplay(head);
	cout<<endl;
	cout<<search(head,20)<<endl;
	cout<<RecSearch(head,20)<<endl;
	head=sortedInsert(head,45);
	head=sortedInsert(head,15);
	display(head);
	cout<<middleOfList(head)<<endl;
	printNthFromEnd(head,2);
	PrintNthFromEnd(head,2);
	cout<<endl;
	head=reverse(head);
	display(head);
	head=recReverse(head);
	display(head);
	head=RecReverse(head,NULL);
	head=RecReverse(head,NULL);
	head=insertAtPos(head,2,20);
	head=insertAtPos(head,4,30);
	head=insertAtPos(head,4,30);
	display(head);
	removeDups(head);
	display(head);
	head=delHead(head);
	display(head);

	return 0;
}