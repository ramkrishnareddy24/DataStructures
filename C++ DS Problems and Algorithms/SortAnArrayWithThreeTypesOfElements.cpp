#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void sortArray(int arr[],int n)
{
	int temp[n],i=0;
	for(int i=0;i<n;i++)
		if(arr[i]==0)
			temp[i]=arr[i];
	for(int j=0;j<n;j++)
		if(arr[j]==1)
		{
			temp[i]=arr[j];
			i++;
		}
	for(int k=0;k<n;k++)
		if(arr[k]==2)
		{
			temp[i]=arr[k];
			i++;
		}

	for(int i=0;i<n;i++)
		arr[i]=temp[i];

}

//also known as Dutch-National-Flag problem
//Efficient Solution
void SortArray(int arr[],int n)
{
	int low=0,mid=0,high=n-1;

	while(mid<=high)
	{
		switch(arr[mid])
		{
			case 0:swap(arr[low],arr[mid]);
					low++; mid++;
					break;
			case 1:mid++;
					break;
			case 2:swap(arr[mid],arr[high]);
					high--;
					break;
		}
	}
}

int main()
{
	int arr[]={0,1,1,2,0,1,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);

	// sortArray(arr,n);

	for(int x:arr)
		cout<<x<<" ";
	cout<<endl;
	SortArray(arr,n);

	for(int x:arr)
		cout<<x<<" ";

}