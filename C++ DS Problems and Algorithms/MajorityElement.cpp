#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int majorityElement(int arr[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			if(arr[i]==arr[j])
				count++;
		if(count>n/2)
			return i;
	}
	return -1;
}

//Efficient Solution //Moore's Voting Algo
int MajorityElement(int arr[],int n)
{
	int count=1;
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(arr[res]==arr[i])
			count++;
		else
			count--;

		if(count==0)
		{
			count=1;
			res=i;
		}
	}

	count=0;
	for(int i=0;i<n;i++)
		if(arr[res]==arr[i])
			count++;

	if(count<=n/2)
		res=-1;
		
	return res;
}

int main()
{
	int arr[]={3, 3, 4, 2, 4, 4, 2, 4, 4};
	int n=sizeof(arr)/sizeof(arr[0]);
	// cout<<" "<<majorityElement(arr,n);
	cout<<" "<<MajorityElement(arr,n);
	return 0;
}