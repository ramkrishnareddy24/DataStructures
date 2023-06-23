#include<iostream>
using namespace std;

void mergeSortFun(int arr[],int l,int m,int h)
{
	int n1=m-l+1,n2=h-m;
	int left[n1],right[n2];

	for(int i=0;i<n1;i++)
		left[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		right[j]=arr[m+1+j];

	int i=0,j=0,k=l;

	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
			arr[k++]=left[i++];
		else
			arr[k++]=right[j++];
	}

	while(i<n1){
		arr[k++]=left[i++];
		
	}

	while(j<n2){
		arr[k++]=right[j++];
	}
}

int main()
{
	int arr[]={10,15,20,40,8,11,15,22,25};
	int i,l=0,h=sizeof(arr)/sizeof(int)-1,m=l+(h-l)/2;

	mergeSortFun(arr,l,m,h);

	for(int i=0;i<h;i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}