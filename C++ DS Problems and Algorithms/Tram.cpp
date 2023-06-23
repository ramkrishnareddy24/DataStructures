#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int capacity=0,tillnow=0;
	
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		tillnow-=a;
		tillnow+=b;
		capacity=max(capacity,tillnow);
		
	}

	cout<<capacity;

	
}
