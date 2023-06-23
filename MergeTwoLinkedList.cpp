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

Node *merge(Node *head1,Node *head2)
{
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;

	Node *temp=NULL;
	Node *curr1=head1;
	Node *curr2=head2;

	while(curr1!=NULL && curr2!=NULL)
	{
		if(curr1->data<=curr2->data){
			temp = insertEnd(temp,curr1->data);
			curr1=curr1->next;
		}
		else{
			temp = insertEnd(temp,curr2->data);
			curr2=curr2->next;
		}		
	}

	while(curr1!=NULL){
		temp = insertEnd(temp,curr1->data);
		curr1=curr1->next;
	}

	while(curr2!=NULL){
		temp = insertEnd(temp,curr2->data);
		curr2=curr2->next;
	}
	return temp;
}


int main()
{
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);

	Node *head2 = new Node(20);
	head2->next = new Node(30);
	head2->next->next = new Node(40);
	head2->next->next->next = new Node(60);

	Node *temp = NULL;
	temp = merge(head,head2);
	display(temp);

	return 0;
}