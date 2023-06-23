#include<iostream>
using namespace std;

int Delete(int arr[],int n,int x)
{
	int i,j;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==x)
			break;
	}
	if(i==n)
		return n;
	for(int j=i;j<n-1;j++)
		arr[j]=arr[j+1];
	return (n-1);
	

}

int main()
{
	int arr[]={1,3,4,5,6};
	int n=sizeof(arr)/sizeof(int);
	int i,x=6;

	cout<<Delete(arr,n,x)<<endl;

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	
	return 0;
}