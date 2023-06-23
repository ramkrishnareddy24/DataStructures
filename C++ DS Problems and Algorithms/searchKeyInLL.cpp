#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int x)
	{
		data=x;
		next=NULL;
	}
};

//Iterative Solution
int searchLL(Node *head,int x)
{
	Node *curr=head;
	int pos=1;

	while(curr!=NULL)
	{
		if(curr->data==x)
		{
			return pos;
		}
		else{
			curr=curr->next;
			pos++;
		}
	}
	return -1;
}

//RecursiveSolution
int recursiveSearchLL(Node *head,int x)
{
	if(head==NULL) return -1;

	if(head->data==x)
		return 1;
	else
	{
		int res=recursiveSearchLL(head->next,x);
		if(res==-1) return -1;
		else
			return res+1;
	}
	
}


int main()
{
	Node *head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	head->next->next->next = new Node(40);

	int x=30;

	cout<<searchLL(head,x);
	cout<<endl;
	cout<<recursiveSearchLL(head,x);

	return 0;
}