#include<bits/stdc++.h>
using namespace std;

int insert(int arr[],int n,int x,int pos,int cap)
{
	if(cap==n)
		return n;
	int idx=pos-1;
	for(int i=n-1;i>=idx;i--)
		arr[i+1]=arr[i];
	arr[idx]=x;
	return (n+1);
}

int deleteEle(int arr[],int n,int x)
{
	int i;
	for(int i=0;i<n;i++)
		if(arr[i]==x)
			break;
	if(i==n)
		return n;
	for(int j=i;j<n-1;j++)
		arr[j]=arr[j+1];
	return (n-1);
}

int largest(int arr[],int n)
{
	int max=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}

int secondLargest(int arr[],int n)
{
	int largest=0,res=-1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[largest])
		{
			res=largest;
			largest=i;
		}else
		if(arr[i]!=arr[largest])
		{
			if(res==-1 || arr[i]>arr[res])
				return res;
		}
	}
	return arr[res];
}

int moveZero(int arr[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
		if(arr[i]!=0)
		{
			swap(arr[i],arr[count]);
			count++;
		}
}

void reverse(int arr[],int n)
{
	int low=0;
	int high=n-1;

	while(low<high)
	{
		swap(arr[low],arr[high]);
		low++;
		high--;
	}
}

void leftRotate(int arr[],int n)
{
	int temp=arr[0];
	for(int i=1;i<n;i++)
		arr[i-1]=arr[i];
	arr[n-1]=temp;
}

int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	// int cap=9;
	// int x=50;
	// int pos=2;

	// insert(arr,n,x,pos,cap);

	// for(int i=0;i<n;i++)
	// 	cout<<arr[i]<<" ";

	// cout<<endl<<deleteEle(arr,n,x)<<endl;;
	// for(int i=0;i<n;i++)
	// 	cout<<arr[i]<<" ";

	// cout<<endl<<largest(arr,n)<<endl;
	// cout<<secondLargest(arr,n);

	// moveZero(arr,n);

	// reverse(arr,n);


	leftRotate(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}