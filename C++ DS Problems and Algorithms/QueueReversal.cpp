#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void print(queue<int>& q)
{
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
}

void reverse(queue<int>& q)
{
	stack<int> s;
	while(!q.empty())
	{
		s.push(q.front());
		q.pop();
	}

	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}

int main()
{
	queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    //print(Queue);
    reverse(Queue);
    print(Queue);
}