#include<bits/stdc++.h>
using namespace std;

int largest(int arr[],int n)
{
	int max=arr[0];
	int res=0;
	for(int i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
			res=i;
		}
	}
	return res;//index Largest
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
		}
		else if(arr[i]!=arr[largest])
		{
			if(res==-1 || arr[i]>arr[res])
				return res;
		}
	}
	return res;
}

int main()
{
	int arr[]={20,30,10,50,15};
	int n=sizeof(arr)/sizeof(int);
	cout<<"largest "<<largest(arr,n)<<endl;
	cout<<"secondLargest "<<secondLargest(arr,n)<<endl;
	return 0;
}