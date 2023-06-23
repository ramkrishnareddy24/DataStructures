/*single linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};*head;

void createlist();
void insertnodeatend(int elmt);
void displaylist();

int main()
{
    int n,element;
    struct node *head;
    printf("Enter the total numbers of nodes: ");
    scanf("%d",&n);
    createlist(n);

    printf("\nEnter the dat to insert at end of list: ");
    scanf("%d",&elmt);
    insertnodeatend(head,elmt);

    printf("\nData in the list \n");
    displaylist();

    return 0;
}

void createlist()
{
    struct node *newnode, *temp;
    int data, i;

    head=(struct node *)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d",&data);

        head->data=data;
        head->next=NULL;

        temp=head;

        for(i=2;i<=n;i++)
        {

            newnode=(struct node *)malloc(sizeof(struct node));

            if(newnode==NULL)
            {
                printf("Unable to allocate memory");
                break;
            }
            else
            {

                printf("Enter the data of node %d: ",i);
                scanf("%d",&data);

                newnode->data=data;
                newnode->next=NULL;

                temp->next=newnode;
                temp=temp->next;

            }
        }
        printf("Singly linked list created\n");

    }
}

 void insertnodeatend(struct node *head, int elmt)
 {
     struct node *newnode, *temp;

     newnode = (struct node*)malloc(sizeof(struct node));

     if(newnode==NULL)
        printf("Unable to allocate memory");
     else
     {
         newnode->data=data;
         newnode->next=NULL;

         temp=head;

         while(temp!=NULL && temp->next!=NULL)
            temp=temp->next;

         temp->next=newnode;
         printf("Data inserted\n");

     }

 }

 void displaylist()
 {
     struct node *temp;

     if(head=NULL)
        printf("List is empty");
     else
     {
         temp=head;
         while(temp!=NULL)
         {
             printf("Data = %d\n",temp->data);
             temp=temp->next;
         }
     }
 }
