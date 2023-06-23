#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void leftRotate(int arr[],int n)
{
	int temp=arr[0];
	for(int i=1;i<n;i++)
		arr[i-1]=arr[i];
	arr[n-1]=temp;
}
void leftRotateByD(int arr[],int n,int d)
{
	for(int i=0;i<d;i++)
		leftRotate(arr,n);
}

//Better Solution
void leftRotateByDBetter(int arr[],int n,int d)
{
	int temp[d];
	for(int i=0;i<d;i++)
		temp[i]=arr[i];
	for(int i=d;i<n;i++)
		arr[i-d]=arr[i];
	for(int i=0;i<d;i++)
		arr[n-d+i]=temp[i];
}

//Best Solution
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