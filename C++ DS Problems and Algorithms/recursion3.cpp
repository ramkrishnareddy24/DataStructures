#include<iostream>
using namespace std;

int power(int n,int x)
{
	if(x==0)
	{
		return 1;
	}
	if(x%2==0)
	{
		return power(n,x/2)*power(n,x/2);
	}
	else
	{
		return n*power(n,x/2)*power(n,x/2);
	}
}


int main()
{
   int n,x;
   cout<<"Enter n and x"<<endl;
   cin>>n>>x;
   cout<<power(n,x);
}