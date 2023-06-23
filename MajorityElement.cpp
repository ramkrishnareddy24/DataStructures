#include<bits/stdc++.h>
using namespace std;

int majorityElement(int arr[],int n)
{
	int res=0;
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[res]==arr[i])
			count++;
		else
			count--;

		if(count==0)
		{
			res=i;
			count=1;
		}
	}
	count=0;
	for(int i=0;i<n;i++)
		if(arr[res]==arr[i])
			count++;
	if(count>n/2)
		res=arr[res];
	else
		res = -1;

	return res;

}

int main()
{
	int arr[]={2,2,1,1,2};
	int n=sizeof(arr)/sizeof(int);
	int res=majorityElement(arr,n);
	cout<<res;

	return 0;
}