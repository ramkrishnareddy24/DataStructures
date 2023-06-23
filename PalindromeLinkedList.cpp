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

bool isPalindrome(Node *head)
{
	if(head->next==NULL) return true;

	vector<int> v;
	Node *curr=head;
	while(curr!=NULL)
	{
		v.push_back(curr->data);
		curr=curr->next;
	}

	int lo=0,hi=v.size()-1;
	while(lo<=hi)
	{
		if(v[lo]!=v[hi])
			return false;
		lo++;
		hi--;
	}
	return true;
}

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

bool Palindrome(Node *head)
{
	if(head->next==NULL) return true;

	Node *slow=head;
	Node *fast=head;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	slow->next = reverse(slow->next);
	slow=slow->next;

	Node *dummy=head;

	while(slow!=NULL)
	{
		if(dummy->data!=slow->data)
			return false;
		dummy=dummy->next;
		slow=slow->next;
	}
	return true;
}

int main()
{
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(10);
	
	if(Palindrome(head))
		cout<<"Plaindrome";
	else
		cout<<"NOT Plaindrome";

	return 0;
}