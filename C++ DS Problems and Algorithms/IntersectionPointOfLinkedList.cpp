#include<iostream>
#include<unordered_set>
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

//Hashing Solution
int intersection(Node *head1,Node *head2)
{
	unordered_set<Node*> s;
	Node *curr1=head1;
	for(curr1=head1;curr1->next!=NULL;curr1=curr1->next)
	{
		s.insert(curr1);
	}

	Node *curr2=head2;
	for(curr2=head2;curr2->next!=NULL;curr2=curr2->next)
	{
		if(s.find(curr2)!=s.end())
			return (curr2->data);
	}
} 

//Iterative Solution
int Intersection(Node *head1,Node *head2)
{
	Node *curr1=head1;
	Node *curr2=head2;

	if(!curr1 || !curr2)
		return -1;

	while(curr1 && curr2 && curr1!=curr2)
	{
		curr1=curr1->next;
		curr2=curr2->next;

		if(curr1==curr2)
			return curr1->data;

		if(!curr1)
			curr1=head2;
		if(!curr2)
			curr2=head1;
	}
	return curr1->data;
}

int main()
{
	Node * head1 = NULL;
	head1 = insertEnd(head1,5);
	head1 = insertEnd(head1,8);
	head1 = insertEnd(head1,7);
	head1 = insertEnd(head1,10);
	head1 = insertEnd(head1,12);
	head1 = insertEnd(head1,15);
	Node *head2;
	head2->next=head1->next->next->next;
	cout<<intersection(head1,head2)<<" ";
	cout<<Intersection(head1,head2);
	return 0;
}