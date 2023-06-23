#include<bits/stdc++.h>
#define size 1000
using namespace std;

class Stack
{
	int top=-1;
public:
	int arr[size];
	int full();
	int empty();
	void push(int ele);
	int pop();
	void display();
	void reverse();
};

int Stack::full()
{
	if(top==size-1)
		return 1;
	else
		return 0;
}

int Stack::empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void Stack::push(int ele)
{
	if(top==size-1)
	{
		cout<<"Stack full";
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
	if(top==-1)
	{
		cout<<"Stack empty";
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
	if(top==-1)
	{
		cout<<"Stack empty";
		return;
	}

	for(int i=top;i>=0;i--)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void Stack::reverse()
{
	if(top==-1)
	{
		cout<<"Stack empty";
		return;
	}

	for(int i=0;i<top;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.display();
	s.pop();
	s.display();

	return 0;
}