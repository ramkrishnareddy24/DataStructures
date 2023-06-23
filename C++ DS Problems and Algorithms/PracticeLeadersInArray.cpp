#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void LeadersArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=i+1;j<n-1;j++)
		{
			if(arr[i]<=arr[j])
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
			cout<<arr[i]<<" ";
	}
}

//Efficient Solution
void leadersArray(int arr[],int n)
{
	int curr_ldr=arr[n-1];
	cout<<curr_ldr<<" ";
	for(int j=n-2;j>=0;j--)
	{
		if(arr[j]>curr_ldr)
		{
			curr_ldr=arr[j];
			cout<<curr_ldr<<" ";
		}
	}
}

int main()
{
	int arr[]={1,3,10,4,2,6,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	LeadersArray(arr,n);cout<<endl;
	leadersArray(arr,n);
	return 0;
}