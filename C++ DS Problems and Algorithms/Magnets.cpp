#include <iostream>
using namespace std;

int Magnets(int arr[],int n)
{
	int c=1;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]!=arr[i+1])
			c++;
	}
	return c;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<Magnets(arr,n);
}