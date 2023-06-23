#include<iostream>
using namespace std;

void Tram(int a[],int b[],int n)
{
	int count1=0,count2=0;

	for(int i=0;i<n;i++)
	{
		count1=count1-a[i];
		count1=count1+b[i];
		count2=max(count1,count2);
	}

	cout<<count2;
}

int main()
{
	int a[1000],b[1000];
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}

	Tram(a,b,n);
}