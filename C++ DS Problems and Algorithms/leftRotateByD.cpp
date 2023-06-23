#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int low,int high)
{
	while(low<high)
	{
		swap(arr[low],arr[high]);
		low++;
		high--;
	}
}
void leftRotateByDBest(int arr[],int n,int d)
{
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);
}
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		int d;
		cin>>d;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		leftRotateByDBest(arr,n,d);
		printArray(arr,n);
	}
}