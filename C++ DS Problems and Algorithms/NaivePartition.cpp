#include<bits/stdc++.h>
using namespace std;

//Naive Partition Solution
void partition(int arr[],int l,int h,int p)
{
	int temp[h-l+1],index=0;
	for(int i=l;i<=h;i++)
	{
		if(arr[i]<=arr[p])
		{
			temp[index]=arr[i];
			index++;
		}
	}

	for(int i=l;i<=h;i++)
	{
		if(arr[i]>arr[p])
		{
			temp[index]=arr[i];
			index++;
		}
	}

	for(int i=l;i<=h;i++)
		arr[i]=temp[i-l];
}

int main()
{
	int arr[]={5,13,6,9,12,11,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	int l=0,h=n-1;
	partition(arr,l,h,6);

	for(int x:arr)
		cout<<x<<" ";
}