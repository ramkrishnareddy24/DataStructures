#include<iostream>
using namespace std;

void EasyOrHard(int a[],int n)
{
	int c1=0;
	for(int i=0;i<n;i++)
		if(a[i]==1)
			c1++;
	if(c1>0)
		cout<<"Hard"<<endl;
	else
		cout<<"Easy"<<endl;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	EasyOrHard(a,n);
	return 0;
}