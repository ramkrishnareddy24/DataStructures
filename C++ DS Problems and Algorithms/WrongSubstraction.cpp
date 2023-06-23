#include<iostream>
using namespace std;

int WrongSub(int n,int k)
{
	while(k!=0)
	{
		if(n%10==0)
			n=n/10;
		else
			n=n-1;
		k--;
	}
	return n;
}

int main()
{
	int n,k;
	cin>>n>>k;

	cout<<WrongSub(n,k);
	
}