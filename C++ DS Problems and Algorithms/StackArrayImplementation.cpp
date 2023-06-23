#include<iostream>
using namespace std;
#define size 1000

class Stack
{
	int top=-1;
public:
	int arr[size];
	void push(int ele);
	int pop();
	void display();
	int full();
	int empty();
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
		cout<<"stack Overflow"<<endl;
		return;
	}
	else{
		top++;
		arr[top]=ele;
	}
}

int Stack::pop()
{
	if(top==-1){
		cout<<"stack Underflow"<<endl;
		return 0;
	}
	else{
	int res=arr[top];
	top--;
	return res;
	}
}

void Stack::display()
{
	for(int i=top;i>=0;i--)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void Stack::reverse()
{
	for(int i=0;i<=top;i++)
	{
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	s.reverse();
}