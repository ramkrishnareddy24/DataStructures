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
Node *top;


void push(int ele)
{
	Node *temp = new Node(ele);
	
	temp->next=top;
	top=temp;
}

int pop()
{
	if(top==NULL)
	{
		cout<<"Underflow"<<endl;
		exit(1);
	}
	else{
		Node *curr=top;
		int res=top->data;
		top=top->next;
		free(curr);
		return res;
	}
}

void display()
{
	if(top==NULL)
	{
		cout<<"stack Underflow"<<endl;
	}
	Node *curr=top;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	cout<<pop()<<endl;
	push(50);
	display();
}