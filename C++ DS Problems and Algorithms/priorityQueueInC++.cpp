#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(10);
	pq.push(15);
	pq.push(5);

	cout<<pq.size()<<endl;
	cout<<pq.top()<<endl;

	while(pq.empty()==false)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}cout<<endl;

	//Another way to implement pq
	int arr[]={10,5,15};
	priority_queue<int> pqu(arr,arr+3);
	for(int i=0;i<pqu.size();i++)
		arr[i]=-arr[i];
	while(pqu.empty()==false)
	{
		cout<<pqu.top()<<" ";
		pqu.pop();
	}


	return 0;
}