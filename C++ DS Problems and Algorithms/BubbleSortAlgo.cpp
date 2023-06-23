#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
//Bubble Sort is Stable Sorting Algo
void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool swapped=false;
		for(int j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		if(swapped==false)
			break;
	}
}

int main()
{
	int arr[]={2,10,8,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}