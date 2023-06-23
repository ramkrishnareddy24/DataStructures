#include<bits/stdc++.h>
using namespace std;

// Moore's Voting Algo //
// Efficient Solution
int majorityElement(int arr[],int n)
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

	return arr[res];
}

int main()
{
	int arr[]={8,8,9,9,9,9,9,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<majorityElement(arr,n);
	return 0;
}