#include<iostream>
using namespace std;

int count(long int n)
{
	if(n/10==0) return 1;

	return count(n/10)+1;
}

int main()
{
	long int n;
	cin>>n;
	cout<<count(n);
}