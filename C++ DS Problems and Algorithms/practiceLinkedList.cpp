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
	temp->next=head;
	return temp;
}

Node *insertEnd(Node *head,int x)
{
	Node *temp=new Node(x);

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
		return NULL;

	Node *curr=head;
	while(curr->next->next!=NULL)
		curr=curr->next;

	delete curr->next;
	curr->next=NULL;

	return head;
}

Node *insertPos(Node *head,int pos,int x)
{
	Node *temp = new Node(x);

	if(pos==1)
	{
		temp->next=head;
		return temp;
	}

	Node *curr=head;
	for(int i=1;i<=pos-2&&curr!=NULL;i++)
		curr=curr->next;

	if(curr==NULL)
		return head;

	temp->next=curr->next;
	curr->next=temp;

	return head;
}

Node *sortedInsert(Node *head,int x)
{
	Node *temp = new Node(x);

	if(head==NULL)
		return temp;
	if(x<head->data)
	{
		temp->next=head;
		return temp;
	}

	Node *curr=head;
	while(curr->next!=NULL && x>curr->next->data)
		curr=curr->next;

	temp->next=curr->next;
	curr->next=temp;

	return head;
}

void middleDisplay(Node *head)
{
	Node *slow=head,*fast=head;
	if(head==NULL)
		return;


	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	cout<<slow->data;
	cout<<endl;
}

void printlist(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;

}

void PrintNthNode(Node *head,int n)
{
	if(head==NULL)
		return;

	Node *first=head;
	for(int i=0;i<n;i++)
	{
		if(head==NULL)
			return;
		first=first->next;
	}

	Node *second=head;
	while(first!=NULL)
	{
		first=first->next;
		second=second->next;
	}
	cout<<second->data<<endl;
}

Node *reverseList(Node *head)
{
	Node *curr=head;
	Node *prev=NULL;

	while(curr!=NULL)
	{
		Node *next=curr->next;
		curr->next=prev;
		prev=curr;

		curr=curr->next;
	}
	return prev;
}

Node *recRevL(Node *head)
{
	if(head==NULL || head->next==NULL)
		return head;

	Node *restHead=recRevL(head->next);
	Node *restTail=head->next;
	restTail->next=head;
	head->next=NULL;
	return restHead;

}

void removeDuplicates(Node *head)
{
	Node *curr = head;

	while(curr!=NULL && curr->next!=NULL)
	{
		if(curr->data == curr->next->data)
		{
			Node *temp = curr->next;
			curr->next = curr->next->next;
			delete(temp);
		}
		curr=curr->next;
	}
}

int main()
{
	Node *head=NULL;
	head = insertBegin(head,10);
	head = insertBegin(head,5);
	head = insertEnd(head,15);
	head = insertEnd(head,20);
	head = insertEnd(head,30);
	printlist(head);
	middleDisplay(head);
	head = delHead(head);
	head = delTail(head);
	printlist(head);
	head = sortedInsert(head,1);
	head = sortedInsert(head,100);
	head = sortedInsert(head,125);
	printlist(head);
	PrintNthNode(head,3);
	head = reverseList(head);
	printlist(head);
	head = recRevL(head);
	printlist(head);
	head = sortedInsert(head,10);
	head = sortedInsert(head,10);
	head = sortedInsert(head,50);
	head = sortedInsert(head,50);
	printlist(head);
	removeDuplicates(head);
	printlist(head);

}