#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	
	Node():data(0),next(NULL){}

	Node(int x)
	{
		data=x;
		next=NULL;
	}
};

Node *addTwoNumbers(Node *l1,Node *l2)
{
	Node *dummy=new Node();
	Node *temp=dummy;

	int carry=0;
	while(l1!=NULL || l2!=NULL || carry)
	{
		int sum=0;
		if(l1!=NULL)
		{
			sum+=l1->data;
			l1=l1->next;
		}

		if(l2!=NULL)
		{
			sum+=l2->data;
			l2=l2->next;
		}

		sum+=carry;
		carry=sum/10;
		Node *node=new Node(sum%10);
		temp->next=node;
		temp=temp->next;
	}
	return dummy->next;
}

void display(Node *head)
{
	Node *curr=head;
	while(curr!=NULL)
	{
		if(curr->next!=NULL)
			cout<<curr->data<<"->";
		else
			cout<<curr->data;
		curr=curr->next;
	}
	cout<<endl;
}

int main()
{
	Node *head1=new Node(2);
	head1->next=new Node(4);
	head1->next->next=new Node(3);

	Node *head2=new Node(5);
	head2->next=new Node(6);
	head2->next->next=new Node(4);

	Node *head = addTwoNumbers(head1,head2);
	display(head);

	return 0;
}