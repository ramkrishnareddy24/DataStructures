#include<iostream>
#define size 5
using namespace std;

class stack
{
	int items[size];
	int top;
	
public:
	stack()
	{
		top=-1;
	}
	int full();
	int empty();
	stack operator--(int);
	friend stack operator+(stack s1,int elem);
	void display(stack &s1);
	
};

int stack::empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int stack::full()
{
	if(top==size)
		return 1;
	else
		return 0;
}

stack operator+(stack s1,int elem)
{
	if(s1.full())
	{
		cout<<"Stack Overflow"<<endl;
	}
	else
	{
		s1.items[++(s1.top)]=elem;
	}
	return s1;
}

stack stack::operator--(int)
{
	if(empty())
	{
		cout<<"Stack Underflow!"<<endl;
	}
	else
	{
		cout<<"The element deleted is :"<<items[top];
		stack t;
		t.top=--top;
		for(int i=0;i<=top;i++)
			t.items[i]=items[i];

	}

	return *this;
}

void stack::display(stack &s1)
{
	for(int i=s1.top;i>=0;i--)
		cout<<s1.items[i]<<" ";
	cout<<endl;

}

int main()
{
	stack s1;
	int choice,elem;

	while(1)
	{
		cout<<"1.PUSH"<<endl<<"2.POP"<<endl<<"3.display"<<endl<<"4.Exit"<<endl;
		cout<<"Enter Your Choice :";  cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter the element to be pushed:";  cin>>elem;
			s1=s1+elem;
			break;

			case 2: s1=s1--;
			break;

			case 3: cout<<"The stack content :";
			s1.display(s1);
			break;

			case 4: exit(0);
			default :cout<<"Enter correct choice"<<endl;
		}
	}
}