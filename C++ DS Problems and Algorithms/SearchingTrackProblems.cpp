#include<bits/stdc++.h>
using namespace std;

//Efficient iterative Solution O(logn)
int binarySearch(int arr[],int n,int x)
{
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(arr[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

//Efficient recursive Solution
int recursiveBinarySearch(int arr[],int low,int high,int x)
{
	if(low>high)
		return -1;

	int mid=(low+high)/2;
	if(arr[mid]==x)
		return mid;
	if(arr[mid]>x)
		return recursiveBinarySearch(arr,low,mid-1,x);
	else
		return recursiveBinarySearch(arr,mid+1,high,x);
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<binarySearch(arr,n,7)<<endl;
	int low=0,high=n-1;
	cout<<recursiveBinarySearch(arr,low,high,7);

	return 0;
}