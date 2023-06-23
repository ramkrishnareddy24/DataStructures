#include<iostream>
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

Node *insertAtBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next=head;
	return temp;
}

Node *insertAtEnd(Node *head,int x)
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
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
	Node *curr=head->next;
	delete head;
	return curr;
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
	delete curr->next;
	curr->next=NULL;
	return head;
}

int search(Node *head,int x)
{
	Node *temp=head;
	int pos=1;
	
	while(temp!=NULL)
	{
		if(temp->data==x){
			return pos;
		}
		else
		{
			temp=temp->next;
			pos++;
		}
	}
	return -1;
}

Node *insertAtPos(Node *head,int pos,int x)
{
	Node *temp = new Node(x);
	pos=1;
	if(head==NULL)
	{
		temp->next=head;
		return temp;
	}
	Node *curr=head;
	for(int i=1;i<pos-2 && curr!=NULL;i++)
	{
		curr=curr->next;
	}
	if(curr==NULL)
		return head;
	temp->next=curr->next;
	curr->next=temp;

	return head;
}

/*
Node *delAtPos(Node *head,int pos)
{
	pos=1;
	Node *curr=head;
	for(int i=1;i<pos-2 && curr!=NULL;i++)
		curr=curr->next;
	
	delete curr->next;
	curr->next=NULL;
	return head;
}
*/


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

void removeDuplicate(Node *head)
{
	Node *curr=head;
	Node *ptr;
	while(curr->next!=NULL)
	{
		if(curr->data==curr->next->data){
			ptr=curr->next->next;
			free(curr->next);
			curr->next=ptr;
		}
		else
		curr=curr->next;
	}
}

int countNodes(Node *head)
{
	int count=0;
	if(head==NULL)
		return NULL;
	Node *curr=head;
	while(curr!=NULL)
	{
		count++;
		curr=curr->next;
	}
	return count;

}

int sumNodes(Node *head)
{
	int sum=0;
	if(head==NULL)
		return 0;
	Node *curr=head;
	while(curr!=NULL)
	{
		sum=sum+curr->data;
		curr=curr->next;
	}
	return sum;
}

//prints Nth Node from end of the linked list
void PrintNthNode(Node *head,int n)
{
	if(head==NULL)
		return;
	Node *first=head;
	for(int i=0;i<n;i++)
	{
		if(first==NULL) return;
		first=first->next;

	}

	Node *second=head;
	while(first!=NULL)
	{
		second=second->next;
		first=first->next;
	}
	cout<<second->data;
}

int minimumNode(Node *head)
{
	int min=INT_MAX;
	while(head!=NULL)
	{
		if(min>head->data)
			min=head->data;
		head=head->next;
	}
	return min;
}

void display(Node *head)
{
	Node *curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<"->";
		curr=curr->next;
	}
}

int main()
{
	Node *head = NULL;
	head = insertAtBegin(head,20);
	head = insertAtBegin(head,10);
	head = insertAtEnd(head,30);
	head = insertAtEnd(head,30);
	head = insertAtEnd(head,100);
	head = insertAtEnd(head,5);
	//head = insertAtPos(head,2,100);
	//head = reverse(head);
	//head = delAtPos(head,2);
	//head = delHead(head);
	//head = delTail(head);
	//int x=30;
	//cout<<search(head,x);
	//removeDuplicate(head);
	display(head);
	cout<<endl;
	cout<<countNodes(head);
	cout<<endl;
	cout<<sumNodes(head)<<endl;
	PrintNthNode(head,1);
	cout<<endl;
	minimumNode(head);
}