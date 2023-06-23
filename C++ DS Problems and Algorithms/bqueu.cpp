#include<bits/stdc++.h>
using namespace std;

struct queue
{
   int cap;
   int sz;
   int *arr;
   int front;
   int rear;
   queue(int c)
   {
    cap=c;
    sz=0;
    arr=new int[cap];
    // front=0;
   // rear=sz-1;
   }
   
   void enqueue(int x)
   {
    if(isempty())
        return;
    rear=getrear();
    rear=(rear+1)%cap;
    arr[rear]=x;
    sz++;
   }
   int dequeue()
   {
    if(isempty())
        return 0;
    int p=arr[front];
    front=(front+1)%cap;
    sz--;
    return p;
    }
    bool isempty()
    {
        return (sz==0);
    }
    bool isfull()
    {
        return (sz==cap);
    }
    int getrear()
    {
         if(isempty())
            return -1;
        else
            return sz-1;
    }



};
int main()
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(13);
    cout<<q.dequeue();
    cout<<q.size();
    q.enqueue(23);
    cout<<q.full();
    cout<<q.isempty();
}


