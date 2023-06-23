#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int n;
	int a[10000]
	int k;

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>k;

	//we have tp process first k elements separately
	deque<int> Q(k);

	for(int i=0;i<k;i++)
	{
		while(!Q.empty() && a[i]>a[Q.back()])
		{
			Q.pop_back(i);
		}

	}
	for(;i<n;i++)
	{
		cout<<a[Q.front()]<<" ";
		//1.remove the elements which are not the prt of the window (Constraction)
		while((!Q.empty() && Q.front()<=i-k)){
			Q.pop_front();
		}
		//2.Remove the elements which are not useful and are in window
		while(!Q.empty() && a[i]>=a[Q.back()])
		{
			Q.pop_back();
		}
		//3.add the new elements(Expansion)
		Q.push_back(i);
	} 


	return 0;
}