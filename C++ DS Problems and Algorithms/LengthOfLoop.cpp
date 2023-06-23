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

int countNodes(Node *head)
{
	int count=1;
	Node *curr=head;
	while(curr->next!=head)
	{
		curr=curr->next;
		count++;
	}
	return count;
}

//Efficient Solution
int lengthOfLoop(Node *head)
{
	Node *slow=head,*fast=head;

	int count=0;
	while(fast!=NULL && fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast)
			return countNodes(slow);
	}
	return 0;
}

int main()
{
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next=head->next;
	cout<<lengthOfLoop(head);
	return 0;
}