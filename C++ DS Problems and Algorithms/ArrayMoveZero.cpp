#include<iostream>
#include<algorithm>
using namespace std;

int MoveZeros(int arr[],int n)
{
    int i,count=0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[count]);
            count++;
        }
    }
}

int main()
{
	int arr[]={1,2,0,5,0,6};
	int n=sizeof(arr)/sizeof(int);

	MoveZeros(arr,n);

	for(auto x:arr)
	{
		cout<<x<<" ";
	}
}
