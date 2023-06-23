#include<iostream>
#include<unordered_set>
using namespace std;

struct Node
{
	int data;
	Node *next;
	// bool visited;
	Node(int x)
	{
		data=x;
		next=NULL;
		// visited=false;
	}
};

// Method-1
bool detectLoop(Node *head)
{
	int x;
	Node *temp = new Node(x);
	Node *curr = head;

	while(curr!=head)
	{
		if(curr->next==NULL)
			return false;
		if(curr->next==temp)
			return true;

		Node *curr_next=curr->next;
		curr->next=temp;
		curr=curr_next;
	}
	return false;
}

// Method-2
bool DetectLoop(Node *head)
{
	unordered_set<Node *> s;

	for(Node *curr=head;curr!=NULL;curr=curr->next)
	{
		if(s.find(curr)!=s.end())
			return true;
		s.insert(curr);
	}
	return false;
}

// Detect Loop in Linked List using
// Floyd's cycle Detection
bool detectLoopFloydsCycle(Node *head)
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

// Detect Loop & Remove Loop from
// the Linked List
void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL || head->next==NULL)
        return;
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

int main()
{
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next=head->next;
	cout<<DetectLoop(head)<<endl;
	cout<<detectLoopFloydsCycle(head)<<endl;
	removeLoop(head);
	cout<<detectLoopFloydsCycle(head)<<endl;
	display(head);
	return 0;
}