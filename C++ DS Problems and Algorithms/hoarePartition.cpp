#include <bits/stdc++.h>
using namespace std;

//Efficient Solution
int hoarePartition(int arr[],int l,int h)
{
	int p=arr[l];
	int i=l-1,j=h+1;

	while(true)
	{
		do
		{
			i++;
		}while(arr[i]<p);

		do
		{
			j--;
		}while(arr[j]>p);

		if(i>=j) return j;
		swap(arr[i],arr[j]);
	}
}

int main()
{
	int arr[]={5,3,8,4,2,7,1,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int l=0,h=n-1;
	hoarePartition(arr,l,h);

	for(int x:arr)
		cout<<x<<" ";
}