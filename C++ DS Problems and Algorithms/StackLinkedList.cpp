#include<bits/stdc++.h>
using namespace std;

struct Stack
{
	int data;
	Stack *next;
	Stack(int x)
	{
		data=x;
		next=NULL;
	}
};
Stack *head;

void push(int ele)
{
	Stack *temp = new Stack(ele);
	temp->next = head;
	head = temp;
}

int pop()
{
	if(head==NULL)
	{
		cout<<"Stack empty";
		return 0;
	}
	else
	{
		Stack *curr=head;
		int res = curr->data;
		head = head->next;
		free(curr);
		return res;
	}
}

void display()
{
	Stack *curr = head;
	if(curr==NULL)
	{
		cout<<"Stack underflow";
		return;
	}
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

int main()
{
	push(1);
	push(2);
	push(3);
	display();
	pop();
	pop();
	pop();
	display();
}