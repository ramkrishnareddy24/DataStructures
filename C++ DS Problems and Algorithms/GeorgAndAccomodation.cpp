#include<iostream>
using namespace std;

int Accomodation(int p[],int q[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(q[i]-p[i]>=2)
			count++;
	}
	return count;
}

int main()
{
	int n;
	cin>>n;
	int p[n],q[n];

	for(int i=0;i<n;i++)
	{
		cin>>p[i]>>q[i];
	}

	cout<<Accomodation(p,q,n);
}