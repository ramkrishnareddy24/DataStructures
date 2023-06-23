#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high)
{
	int n1=mid-low+1,n2=high-mid;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)
	{
		left[i]=arr[low+i];
	}
	for (int j = 0; j < n2; j++)
	{
		/* code */
		right[j]=arr[mid+1+j];
	}
	int i=0,j=0,k=low;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;k++;
		}	
		else
		{
			arr[k]=right[j];
			k++;
			j++;
		}
	
	}
	while(i<n1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}



void mergesort(int arr[],int l,int r)
{
	if(r>l)
	{
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
	
}

// void print(int arr[],int n)
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		cout<<arr[i]<<" ";
// 	}
// }

// int main()
// {
// 	int n;
// 	cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>arr[i];
// 	}
// 	int l=0,r=n-1;
// 	mergesort(arr,l,r);
// 	print(arr,n);
// }

int main()
{
	int arr[]={10,5,30,15,7};
	int n=sizeof(arr)/sizeof(int);
	int l=0,r=n-1;

	mergesort(arr,l,r);

	for(auto x:arr)
	{
		cout<<x<<" ";
	}
}