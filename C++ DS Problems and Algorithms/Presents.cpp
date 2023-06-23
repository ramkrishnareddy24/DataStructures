#include<iostream>
using namespace std;

void Presents(int arr[],int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}

int main()
{
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		arr[k]=i;
	}

	Presents(arr,n);
}