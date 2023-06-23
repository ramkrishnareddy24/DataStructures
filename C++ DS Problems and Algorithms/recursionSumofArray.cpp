#include<iostream>
using namespace std;

int sum(int arr[],int n)
{
	int res;
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return n;
	}
	return sum(n-1)+n;
}
int main()
{
	int arr[100];
	int i,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<sum(arr,n);
}