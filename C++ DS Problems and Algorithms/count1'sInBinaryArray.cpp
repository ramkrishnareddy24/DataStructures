#include<bits/stdc++.h>
using namespace std;

// Naive Solution
int count1s(int arr[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
		if(arr[i]==1)
			count++;
	return count;
}

//Efficient Solution
int count1sBinaryArray(int arr[],int n)
{
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==0)
			low=mid+1;
		else
		{
			if(mid==0 || arr[mid-1]==0)
				return (n-mid);
			
			else
				low=mid-1;
		}
	}
}

int main()
{
	int arr[]={0,0,0,1,1,1,1,1,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	// cout<<count1s(arr,n)<<endl;
	cout<<count1sBinaryArray(arr,n);
	return 0;
}