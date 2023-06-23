#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int oddOccuring(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
			if(arr[i]==arr[j])
				count++;

		if(count%2!=0)
			return arr[i];
	}
}

//Efficient Solution
int OddOccuring(int arr[],int n)
{
	int res=0;
	for(int i=0;i<n;i++)
		res=res^arr[i];
	return res;
}

//Variant of same problem
//find the missing number in array of given range
int getMissingNo(int arr[],int n)
{
	int x1=arr[0];
	int x2=1;

	for(int i=1;i<n;i++)
		x1=x1^arr[i];
	for(int i=2;i<=n+1;i++)
		x2=x2^i;

	return (x1^x2);
}


int main()
{
	int arr[]={1,2,4,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	// cout<<oddOccuring(arr,n);
	// cout<<" "<<OddOccuring(arr,n);
	cout<<getMissingNo(arr,n);

	return 0;
}
