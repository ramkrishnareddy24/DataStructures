#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int kthSmallest(int arr[],int n,int k)
{
	sort(arr,arr+n);
	return arr[k-1];
}

int lomutoPartition(int arr[],int l,int h)
{
	int p=arr[h];
	int i=l-1;

	for(int j=l;j<=h-1;j++)
	{
		if(arr[j]<p)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;
}

//Effcient Solution
int KthSmallest(int arr[],int n,int k)
{
	int l=0,r=n-1;

	while(l<=r)
	{
		int p=lomutoPartition(arr,l,r);

		if(p==k-1)
			return arr[p];
		if(p>k-1)
			r=p-1;
		else
			l=p+1;
	}
	return -1;
}


int main()
{
	int arr[]={7,10,4,3,20,15};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<kthSmallest(arr,n,5)<<endl;
	cout<<KthSmallest(arr,n,3);
	return 0;
}