#include<iostream>
#include<algorithm>
using namespace std;

int ReverseArray(int arr[],int n)
{
	int low=0,high=n-1;
	while(low<high)
	{
		swap(arr[low],arr[high]);
		low++;
		high--;
	}
}

int main()
{
	int arr[]={1,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(int);

	ReverseArray(arr,n);

	for(auto x:arr)
	{
		cout<<x<<" ";
	}
}