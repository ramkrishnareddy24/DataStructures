#include<bits/stdc++.h>
#define size 1000
using namespace std;

class Stack
{
	int top=-1;
public:
	int arr[size];
	int isFull();
	int isEmpty();
	void push(int ele);
	int pop();
	void display();
	
};

int Stack::isFull()
{
	if(top==size-1)
		return 1;
	else
		return 0;
}

int Stack::isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void Stack::push(int ele)
{
	if(isFull())
	{
		cout<<"Stack is Full"<<endl;
		return;
	}
	else
	{
		top++;
		arr[top]=ele;
	}
}

int Stack::pop()
{
	if(isEmpty())
	{
		cout<<"Stack Empty"<<endl;
		return 0;
	}
	else
	{
		int res=arr[top];
		top--;
		return res;
	}
}

void Stack::display()
{
	if(isEmpty())
	{
		cout<<"Stack is Empty"<<endl;
		return;
	}
	else
	for(int i=top;i>=0;i--)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	s.pop();
	s.display();
	 
	return 0;
}