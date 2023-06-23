#include<iostream>
using namespace std;

//Efficient Solution
int closer(int arr[],int n,int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(mid>0 && arr[mid-1]==x)
			return mid-1;
		else if(mid<n && arr[mid+1]==x)
			return mid+1;
		else if(x>arr[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;	
}

int main()
{
	int arr[]={3 ,2 ,10 ,4 ,40};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<closer(arr,n,2);
	return 0;
}