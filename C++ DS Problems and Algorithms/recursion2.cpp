#include<iostream>
using namespace std;

int factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	int SmallOutput=factorial(n-1);
	int Output=n*SmallOutput;
	return Output;
}
int main()
{
	cout<<factorial(5);
	
}