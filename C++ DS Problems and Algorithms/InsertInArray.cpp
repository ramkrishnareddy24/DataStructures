#include<bits/stdc++.h>
using namespace std;

int insert(int arr[],int x,int n,int pos,int cap)
{
	if(n==cap)
		return n;
	int idx=pos-1;
	for(int i=n-1;i>=idx;i--)
		arr[i+1]=arr[i];
	arr[idx]=x;
	
	return (n+1);
}

int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	int cap=9;
	int x=99;
	int pos=2;

	insert(arr,x,n,pos,cap);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}