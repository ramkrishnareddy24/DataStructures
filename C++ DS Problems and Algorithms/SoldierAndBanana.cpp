#include<iostream>
using namespace std;


int main()
{
	int k,n,w,i;
	long long int count=0;
	cin>>k>>n>>w;

	for(int i=1;i<=w;i++)
	{
		count+=k*i;
	}

	if(count<=n)
	{
		cout<<0;
		
	}
	else
	{
		cout<<(count-n);
	}

}