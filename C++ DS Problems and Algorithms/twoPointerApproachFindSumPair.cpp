#include<bits/stdc++.h>
using namespace std;

//Naive Solution
bool ispair(int arr[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			if(arr[i]+arr[j]==x)
				return true;
	}
	return false;
}

//Two Pointer Approach
//Efficient Solution
bool isPair(int arr[],int n,int x)
{
	int left=0;
	int right=n-1;

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

int main()
{
	int arr[]={2,4,8,9,11,12,20,30};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<isPair(arr,n,23);
	return 0;
}