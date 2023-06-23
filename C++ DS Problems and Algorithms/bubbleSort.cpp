//Optimized bubbleSort
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n)
{
	int i,j;
	for(int i=0;i<n-1;i++)
	{
		int swapped=false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1])
			{
				/*int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;*/
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}
		if(swapped==false)
			break;
	}
	
}

int main()
{
	int arr[]={10,8,2};
	int i,n=sizeof(arr)/sizeof(int);

	bubbleSort(arr,n);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}