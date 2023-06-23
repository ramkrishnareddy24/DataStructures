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

int intersection(Node *head1,Node *head2)
{
	unordered_set<int> s;
	Node *curr1=head1;
	for(curr1=head1;curr1!=NULL;curr1=curr1->next)
		s.insert(curr1->data);

	Node *curr2=head2;
	for(curr2=head2;curr2!=NULL;curr2=curr2->next)
		if(s.find(curr2->data)!=s.end())
			return curr2->data;
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(7);

	Node *head2 = new Node(3);
	head2->next = new Node(2);
	head2->next->next = new Node(4);
	// head2->next->next->next = new Node(60);

	int in = intersection(head,head2);
	cout<<in;

	return 0;
}