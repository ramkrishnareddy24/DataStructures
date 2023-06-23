#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int peakElement(int arr[],int n)
{
	if(n==1) return arr[0];
	if(arr[0]>=arr[1]) return arr[0];
	
	for(int i=1;i<n;i++)
		if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
			return arr[i];

	if(arr[n-1]>=arr[n-2]) return arr[n-1];
}

//Efficient Solution
int PeakElement(int arr[],int n)
{
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;

		if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
			return arr[mid];

		if(mid>0 && arr[mid-1]>=arr[mid])
			high=mid-1;
		else
			low=mid+1;
	}
}

int main()
{
	int arr[]={5,20,40,30,20,50,60};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<peakElement(arr,n)<<" ";
	cout<<PeakElement(arr,n);
	return 0;
}