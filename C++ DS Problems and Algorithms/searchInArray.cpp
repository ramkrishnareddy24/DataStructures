#include<iostream>
using namespace std;

int search(int arr[],int n,int key)
{
	for(int i=0;i<n;i++)
	
		if(arr[i]==key)
			return i;
		return -1;
	
}

int main()
{
	int arr[]={1,2,3,4,5};
	int i,key=2;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<search(arr,n,key);
}