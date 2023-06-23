#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void sortArray(int arr[],int n)
{
	int temp[n],i=0;

	for(int i=0;i<n;i++)
		if(arr[i]<0)
			temp[i]=arr[i];
	for(int j=0;j<n;j++)
		if(arr[j]>=0)
		{
			temp[i]=arr[j];
			i++;
		}
		
	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}

//also Known Binary-Array-Sorting-Algo
//Efficient Solution
void SortArray(int arr[],int n)
{
	int i=-1,j=n;

	while(true)
	{
		do
		{
			i++;
		}while(arr[i]<0);

		do
		{
			j--;
		}while(arr[j]>=0);

		if(i>=j)
			return;
		swap(arr[i],arr[j]);
	}
}

int main()
{
	int arr[]={13,-12,18,-10};
	int n=sizeof(arr)/sizeof(arr[0]);

	sortArray(arr,n);
	for(int x:arr)
		cout<<x<<" ";
	cout<<endl;

	SortArray(arr,n);

	for(int x:arr)
		cout<<x<<" ";

}