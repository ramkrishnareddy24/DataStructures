#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
    
};

ListNode *merge(ListNode *l1,ListNode *l2)
{
    ListNode *ptr = NULL;
    ListNode *curr = ptr;

    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val<=l2->val)
        {
            curr->next=l1;
            l1=l1->next;
        }
        else
        {
            curr->next=l2;
            l2=l2->next;
        }
        curr=curr->next;
    }

    while(l1!=NULL) {
        curr->next=l1;
        l1=l1->next;
    }
    while(l2!=NULL) {
        curr->next=l2;
        l2=l2->next;
    }

    return curr->next;
}

ListNode* sortList(ListNode* head) {

    if(head == NULL || head ->next == NULL)
            return head;

    ListNode *slow=head;
    ListNode *fast=head;
    ListNode *temp=NULL;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    slow=slow->next;

    temp->next=NULL;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);

    return merge(l1,l2);
}

void display(ListNode *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
}

int main()
{
    ListNode *head=new ListNode(4);
    head->next=new ListNode(2);
    head->next->next=new ListNode(1);
    head->next->next->next=new ListNode(3);
    display(head);
    sortList(head);
    display(head);
}