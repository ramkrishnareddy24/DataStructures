#include<iostream>
using namespace std;

// Recursive Solution
// int sumOfArray(int arr[],int n)
// {
// 	if(n==0)
// 		return n;
// 	return arr[n-1]+sumOfArray(arr,n-1);
// }

int sumOfArray(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	return sum;
}

int main()
{
	int n,i;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<sumOfArray(arr,n);
	
}