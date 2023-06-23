#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;


void query_print(priority_queue<int,vector<int>,greater<int>> pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}
int main()
{
	  int no;

	  //To find the largest k numbers (query points)
	  priority_queue<int,vector<int>,greater<int> > pq;
	  int cs=0;
	  int k=3;

	  while(scanf("%d",&no)!=EOF)
	  {
	  	if(no==-1)
	  	{
	  		query_print(pq);
	  	}
	  	else if(cs<k)
	  	{
	  		pq.push(no);
	  		cs++;
	  	}
	  	else {
	  		if(no>pq.top())
	  		{
	  			pq.pop();
	  			pq.push(no);
	  		}
	  	}
	  	
	  }


	  return 0;
}