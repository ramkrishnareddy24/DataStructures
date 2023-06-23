#include<bits/stdc++.h>
using namespace std;

int countInversions(int arr[],int n)
{
	int res=0;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n;j++)
			if(arr[j]>arr[i])
				res++;
	return res;
}

int Merge(int arr[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int left[n1],right[n2];

	for(int i=0;i<n1;i++)
		left[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		right[j]=arr[m+1+j];

	int i=0,j=0,k=l;
	int res=0;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
			arr[k++]=left[i++];
		else
		{
			arr[k++]=right[j++];
			res+=(n1-i);
		}
	}

	while(i<n1) arr[k++]=left[i++];
	while(j<n2) arr[k++]=right[j++];

	return res;
}

int CountInversions(int arr[],int l,int r)
{
	int res=0;
	if(r>l)
	{
		int m=l+(r-l)/2;
		res+=CountInversions(arr,l,m);
		res+=CountInversions(arr,m+1,r);
		res+=Merge(arr,l,m,r);
	}
	return res;
}

int main()
{
	int arr[]={5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int Inversions=CountInversions(arr,0,n-1);
	int inversions=countInversions(arr,n);

	cout<<inversions<<" "<<Inversions;

	return 0;
}