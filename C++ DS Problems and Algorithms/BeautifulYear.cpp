#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int countDigit(int n)
{
	int c=0;
	while(n)
	{
		int r=n%10;
		c++;
		n=n/10;
	}
	return c;
}

int countDistinct(int n)
{
	int count=0;
	int arr[10]={0};
	while(n)
	{
		int r=n%10;
		arr[r]=1;
		n=n/10;
	}

	for(int i=0;i<10;i++)
	{
		if(arr[i])
			count++;
	}
	return count;
}

int beautifulYear(int n)
{
	while(n<INT_MAX)
	{
		int totaldigits=countDigit(n+1);
		int distinctDigits=countDistinct(n+1);

		if(distinctDigits==totaldigits)
		{
			return n+1;
		}
		else
			n++;
	}
	return -1;
}

int main()
{
	int y;
	cin>>y;

	cout<<beautifulYear(y);

}