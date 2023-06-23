//Efficient Solution
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
        
        // if it is circularLL
        if(fast==head)
        {
            Node *curr=head;
            while(curr->next!=head)
                curr=curr->next;
            curr->next=NULL;
        }
        else // if loop is connected to other node next to head
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