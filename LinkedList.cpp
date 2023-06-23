#include<bits/stdc++.h>
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
	
Node *insertBegin(Node *head,int x)
{
	Node *temp = new Node(x);
	temp->next = head;
	return temp;
}

Node *insertEnd(Node *head,int x)
{
	Node *temp = new Node(x);

	if(head==NULL)
		return temp;

	Node *curr=head;
	while(curr->next!=NULL)
		curr=curr->next;

	curr->next=temp;

	return head;
}

Node *deleteHead(Node *head)
{
	if(head==NULL)
	{
		return NULL;
	}
	else if(head->next==NULL)
	{
		delete head;
		return NULL;
	}	
	else
	{
		Node *temp=head->next;
		delete head;
		return temp;
	}
}

Node *deleteTail(Node *head)
{
	if(head==NULL) return NULL;
	else if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node *curr=head;
	while(curr->next->next!=NULL)
		curr=curr->next;

	delete curr->next;
	curr->next=NULL;
	return head;
}

void display(Node *head)
{
	Node *curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

Node *insertAtPos(Node *head,int pos,int x)
{
	Node *temp = new Node(x);

	if(pos==1)
	{
		temp->next=head;
		return temp;
	}

	Node *curr=head;
	for(int i=1;i<=pos-2 && curr!=NULL;i++)
		curr=curr->next;

	temp->next=curr->next;
	curr->next=temp;

	return head;
}

Node *sortedInsert(Node *head,int x)
{
	Node *temp = new Node(x);

	if(head==NULL)
		return temp;

	if(head->data>x)
	{
		temp->next=head;
		return temp;
	}

	Node *curr=head;
	while(curr->next!=NULL && curr->next->data<x)
		curr=curr->next;

	temp->next=curr->next;
	curr->next=temp;

	return head;
}

void MiddleOfLinkedList(Node *head)
{
	if(head==NULL) return;

	Node *slow = head;
	Node *fast = head;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	cout<<slow->data<<endl;
}

void NthNode(Node *head,int n)
{
	if(head==NULL) return;

	Node *first=head;
	for(int i=0;i<n;i++)
	{
		if(first==NULL)
			return;
		first=first->next;
	}

	Node *second=head;
	while(first!=NULL)
	{
		second=second->next;
		first=first->next;
	}

	cout<<second->data<<endl;
}

Node *reverseNaive(Node *head)
{
	Node *curr=head;
	vector<int> arr;
	for(curr=head;curr!=NULL;curr=curr->next)
		arr.push_back(curr->data);
	for(curr=head;curr!=NULL;curr=curr->next)
	{
		curr->data = arr.back();
		arr.pop_back();
	}
	return head;
}

// Efficient
Node *reverse(Node *head)
{
	Node *curr=head;
	Node *prev=NULL;

	while(curr!=NULL)
	{
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

Node *removeDuplicate(Node *head)
{
	Node *curr=head;
	Node *ptr;

	while(curr->next!=NULL)
	{
		if(curr->data==curr->next->data)
		{
			ptr=curr->next->next;
			free(curr->next);
			curr->next=ptr;
		}
		else
			curr=curr->next;
	}
	return head;
}

Node *reverseInGroupsOfK(Node *head,int k)
{
	Node *curr=head;
	Node *prev=NULL;
	Node *next=NULL;
	int count=0;

	while(curr!=NULL && count<k)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		
		count++;
	}

	if(next!=NULL)
	{
		Node *rest_head = reverseInGroupsOfK(head,k);
		head->next=rest_head;
	}

	return prev;
}

int detectLoop(Node *head)
{
	Node *slow=head;
	Node *fast=head;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast)
			return true;
	}
	return false;
}

void removeLoop(Node *head)
{
	Node *slow=head;
	Node *fast=head;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast)
			break;
	}

	if(slow!=fast)
		return;

	if(fast==head)
	{
		Node *curr=head;
		while(curr->next!=head)
			curr=curr->next;
		curr->next=NULL;
	}
	else
	{
		slow=head;
		while(slow->next!=fast->next)
		{
			slow=slow->next;
			fast=fast->next;
		}
		fast->next=NULL;
	}
}

Node *segregateEvenOdd(Node *head)
{
	Node *oS=NULL,*oE=NULL,*eS=NULL,*eE=NULL;
	for(Node *curr=head;curr!=NULL;curr=curr->next)
	{
		int x=curr->data;
		if(x%2==0)
		{
			if(eS==NULL)
			{
				eS=curr;
				eE=eS;
			}
			else
			{
				eE->next=curr;
				eE=eE->next;
			}
		}
		else
		{
			if(oS==NULL)
			{
				oS=curr;
				oE=oS;
			}
			else
			{
				oE->next=curr;
				oE=oE->next;
			}
		}
	}
	if(oS==NULL || eS==NULL)
		return NULL;
	eE->next=oS;
	oE->next=NULL;
	return eS;
}


int intersection(Node *head1,Node *head2)
{
	unordered_set<int> s;
	Node *curr1=head1;

	for(curr1=head1;curr1!=NULL;curr1=curr1->next)
		s.insert(curr1->data);

	Node *curr2=head2;
	for(curr2=head2;curr2!=NULL;curr2=curr2->next)
		if(s.find(curr2->data)!=s.end())
			return curr2->data;
}

int main()
{
	Node *head = new Node(10);
	head = insertBegin(head,5);
	head = insertEnd(head,20);
	display(head);
	head = deleteHead(head);
	display(head);
	head = deleteTail(head);
	display(head);
	head = insertEnd(head,30);
	head = insertEnd(head,40);
	head = insertEnd(head,50);
	display(head);
	head = insertAtPos(head,3,35);
	display(head);
	head = sortedInsert(head,45);
	head = sortedInsert(head,15);
	display(head);
	MiddleOfLinkedList(head);
	NthNode(head,3);
	head = reverseNaive(head);
	display(head);
	head = reverse(head);
	display(head);
	head = sortedInsert(head,30);
	display(head);
	head = removeDuplicate(head);
	display(head);
	cout<<"detectLoop :"<<detectLoop(head)<<endl;
	Node *curr=head;
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=head->next;
	cout<<"detectLoop :"<<detectLoop(head)<<endl;
	removeLoop(head);
	cout<<"detectLoop :"<<detectLoop(head)<<endl;
	return 0;
}