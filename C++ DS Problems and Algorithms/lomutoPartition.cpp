#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
void lomutoPartition(int arr[],int l,int h)
{
	int p=arr[h];
	int i=l-1;

	for(int j=l;j<=h;j++)
	{
		if(arr[j]<p)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
}

int main()
{
	int arr[]={10,80,30,90,40,50,70};
	int n=sizeof(arr)/sizeof(arr[0]);
	int l=0,h=n-1;
	lomutoPartition(arr,l,h);

	for(int x:arr)
		cout<<x<<" ";
}