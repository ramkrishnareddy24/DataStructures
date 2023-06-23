#include<bits/stdc++.h>
using namespace std;

//Naive Solution
bool Triplet(int arr[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
				if(arr[i]+arr[j]+arr[k]==x)
					return true;
		}
	}
	return false;
}


//Efficient Solution
bool isPair(int arr[],int left,int right,int x)
{
	while(left<right)
	{
		if(arr[left]+arr[right]==x)
			return true;
		else if(arr[left]+arr[right]>x)
			right--;
		else
			left++;
	}
	return false;
}

bool tripletSum(int arr[],int n,int x)
{
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
		if(isPair(arr,i+1,n-1,x-arr[i]))
			return true;
	return false;
}

int main()
{
	int arr[]={2,3,4,8,9,20,40};
	int n=sizeof(arr)/sizeof(arr[0]);
	int left=0,right=n-1;
	cout<<Triplet(arr,n,32)<<" ";
	cout<<tripletSum(arr,n,32);
	return 0;
}