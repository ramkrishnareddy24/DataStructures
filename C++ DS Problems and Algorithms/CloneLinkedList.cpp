#include<iostream>
#include<unordered_map>
using namespace std;

struct Node
{
	int data;
	Node *next,*random;
	Node(int x)
	{
		data=x;
		next=random=NULL;
	}
};

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

//Hashing Solution
Node *Clone(Node *head)
{
	unordered_map<Node*,Node*> hm;

	for(Node *curr=head;curr!=NULL;curr=curr->next)
		hm[curr]=new Node(curr->data);

	for(Node *curr=head;curr!=NULL;curr=curr->next)
	{
		Node *cloneCurr=hm[curr];
		cloneCurr->next=hm[curr->next];
		cloneCurr->random=hm[curr->random];
	}
	Node *head2=hm[head];

	return head2;
}

//Tricky Efficient Solution
Node *clone(Node *head) 
{ 
    Node *next,*temp;
    for(Node *curr=head;curr!=NULL;)
    {
        next=curr->next;
        curr->next=new Node(curr->data);
        curr->next->next=next;
        curr=next;
    }


    for(Node *curr=head;curr!=NULL;curr=curr->next->next)
        curr->next->random=(curr->random!=NULL)?(curr->random->next):NULL;

    
    Node *original = head, *copy = head->next; 
  
    temp = copy; 
  
    while (original && copy) 
    	
    { 
        original->next = original->next? original->next->next : original->next; 
        copy->next = copy->next? copy->next->next : copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 

    return temp;
}


int main()
{
	
	Node *head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	head->next->next->next=new Node(4);
	head->next->next->next->next=new Node(5);

    // 1's random points to 3
    head->random = head->next->next;
 
    // 2's random points to 1
    head->next->random = head;
 
    // 3's and 4's random points to 5
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
 
    // 5's random points to 2
    head->next->next->next->next->random = head->next;

    display(head);
    head = Clone(head);
    display(head);
    head = clone(head);
    display(head);
    head = clonell(head);
    display(head);
}