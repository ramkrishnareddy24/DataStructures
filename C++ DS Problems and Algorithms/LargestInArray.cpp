#include<iostream>
using namespace std;

int Largest(int arr[],int n)
{
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[res])
			res=i;
	}
	return arr[res];
}

int SecondLargest(int arr[],int n)
{
	int res=-1,largest=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[largest])
		{
			res=largest;
			largest=i;
		}
		else if(arr[i]!=arr[largest])
		{
			if(arr[i]!=-1 || arr[i]>arr[res])
			{
				res=i;
			}
		}
	}
	return arr[res];
} 

int main()
{
	int arr[]={1,20,30,45,40,44};
	int n=sizeof(arr)/sizeof(int);

	cout<<"Largest Ele is :"<<Largest(arr,n)<<endl;
	cout<<"Second Largest Ele is :"<< SecondLargest(arr,n);

}