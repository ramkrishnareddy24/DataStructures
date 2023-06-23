#include<iostream>
using namespace std;

int VanyaAndFence(int n,int h,int arr[])
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=h)
			count++;
		if(arr[i]>h)
			count=count+2;
	}

	return count;
}

int main()
{
	int n;
	cin>>n;
	int h;
	cin>>h;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<VanyaAndFence(n,h,arr);
}