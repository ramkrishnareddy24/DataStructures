#include<iostream>
using namespace std;

int SumofDigit(int n)
{
	if(n<10)
		return n;
	return SumofDigit(n/10)+(n%10);
}

int main()
{
	int n;
	cin>>n;
	cout<<SumofDigit(n);
}