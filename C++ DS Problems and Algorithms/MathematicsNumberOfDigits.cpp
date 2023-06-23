#include<bits/stdc++.h>
using namespace std;

//Iterative Solution
int findNumDigits(long n)
{
	int count=0;
	while(n!=0)
	{
		n=n/10;
		count++;
	}
	return count;
}

//Recursive Solution
int findNumDigits_rec(long n)
{
	if(n==0)
		return 0;
	return 1+(findNumDigits_rec(n/10));
}

//Logarithmic Solution
int findNumDigits_log(long n)
{
	return floor(log10(n)+1); 
} 

int main()
{
	long n=123;
	cout<<findNumDigits(n)<<" ";
	cout<<findNumDigits_rec(n)<<" ";
	cout<<findNumDigits_log(n)<<" ";
	return 0;
}