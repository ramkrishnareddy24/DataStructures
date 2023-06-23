#include<iostream>
#include<queue>
using namespace std;

int main()
{
	priority<int> pq_max;
	priority_queue<int,vector<int>,greater<int> > pq;
	int n;
	cin>>n; 

	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		pq.push(no);
	}
	//Remove the elements from the heap
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}


	return 0;
}