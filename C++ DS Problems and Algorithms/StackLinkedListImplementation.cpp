#include<iostream>
using namespace std;

struct stack
{
	int data;
	stack *next;
	stack(int x)
	{
		data=x;
		next=NULL;
	}
};
stack *head;

void push(int x)
{
	stack *temp = new stack(x);
	temp->next=head;
	head=temp;
}

void display()
{
	stack *curr=head;
	if(curr==NULL)
	{
		cout<<"Underflow"<<endl;
	}
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

int pop()
{
	if(head==NULL)
	{
		cout<<"Stack Underflow"<<endl;
		exit(1);
	}
	else
	{
		int res=head->data;
		stack *curr=head;
		head=head->next;
		free(curr);
		return res;
	}
	
}


int main()
{
	push(50);
	push(40);
	push(30);
	pop();
	pop();
	display();
}