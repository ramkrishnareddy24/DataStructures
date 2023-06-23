#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

Node *insertAtBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next = head;
	return temp;
}

void printList(Node *head)
{
	while(head!=0)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main()
{
	Node *head = NULL;
	head = insertAtBegin(head,30);
	head = insertAtBegin(head,20);
	head = insertAtBegin(head,10);

	printList(head);

	return 0;
}