#include<iostream>
using namespace std;

int LeftRotate(int arr[],int n)
{
	int i,temp=arr[0];
	for(int i=0;i<n;i++)
	 arr[i-1]=arr[i];
	arr[n-1]=temp;

}

int main()
{
	int arr[]={1,2,3,4};
	int n=sizeof(arr)/sizeof(int);

	LeftRotate(arr,n);

	for(auto x:arr)
	{
		cout<<x<<" ";
	}

	return 0;
}