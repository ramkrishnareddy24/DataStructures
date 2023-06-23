#include<bits/stdc++.h>
using namespace std;

//Naive Solution
bool powerOfTwo(int n)
{
	if(n==0)
		return false;

	while(n!=1)
	{
		if(n%2!=0)
			return false;
		n=n/2;
	}
	return true;
}

//Efficient Solution
bool isPowerOfTwo(int n)
{
	return (n!=0)&&((n&(n-1))==0);
}

int main()
{
	int n=16;
	cout<<powerOfTwo(n);
	cout<<" "<<isPowerOfTwo(n);
	return 0;
}