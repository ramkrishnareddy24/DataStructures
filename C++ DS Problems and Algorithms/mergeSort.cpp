//Merge two sorteed arrays
#include<iostream>
using namespace std;

int merge(int arr1[],int arr2[],int m,int n)
{
	int i=0,j=0;
	while(i<m && j<n)
		if(arr1[i]<arr2[j])
			cout<<arr1[i++]<<" ";
		else
			cout<<arr2[j++]<<" ";
	while(i<m)
		cout<<arr1[i++]<<" ";
	while(j<n)
		cout<<arr2[j++]<<" ";

}



int main()
{
	int arr1[]={5,6,10,10,15,20};
	int arr2[]={10,15,20,40};
	int m=sizeof(arr1)/sizeof(int);
	int n=sizeof(arr2)/sizeof(int);

	merge(arr1,arr2,m,n);

}