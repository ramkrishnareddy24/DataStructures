#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void countSort(int arr[],int n,int k)
{
	int count[k];
	for(int i=0;i<k;i++)
		count[i]=0;
	for(int i=0;i<n;i++)
		count[arr[i]]++;

	int index=0;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<count[i];j++)
		{
			arr[index]=i;
			index++;
		}
	}
}

//Effcient Solution
void CountSort(int arr[],int n,int k)
{
	int count[k];
	for(int i=0;i<k;i++)
		count[i]=0;

	for(int i=0;i<n;i++)
		count[arr[i]]++;

	for(int i=1;i<k;i++)
		count[i]+=count[i-1];

	int output[n];
	for(int i=n-1;i>=0;i--)
	{
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}

	for(int i=0;i<n;i++)
		arr[i]=output[i];
}

int main()
{
	int arr[]={1,4,4,1,0,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	countSort(arr,n,5);

	for(int x:arr)
		
		cout<<x<<" ";
	cout<<endl;

	CountSort(arr,n,5);

	for(int x:arr)
		cout<<x<<" ";

	return 0;
}