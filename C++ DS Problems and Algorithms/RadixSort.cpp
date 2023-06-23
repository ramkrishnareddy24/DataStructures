#include<iostream>
using namespace std;

void countSort(int arr[],int n,int exp)
{
	int count[10],output[n];

	for(int i=0;i<10;i++)
		count[i]=0;
	for(int i=0;i<n;i++)
		count[(arr[i]/exp)%10]++;

	for(int i=1;i<10;i++)
		count[i]=count[i]+count[i-1];

	for(int i=n-1;i>=0;i--){
		output[count[(arr[i]/exp)%10]-1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}

	for(int i=0;i<n;i++)
		arr[i]=output[i];

}

void RadixSort(int arr[],int n)
{
	int max=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>max)
			max=arr[i];
	}


	for(int exp=1;max/exp>0;exp*=10)
		countSort(arr,n,exp);
}

int main()
{
	int arr[]={319,212,6,8,100,50};
	int n=sizeof(arr)/sizeof(int);
	

	RadixSort(arr,n);

	for(int i:arr)
	{
		cout<<i<<" ";
	}

}