#include<bits/stdc++.h>
using namespace std;

//Effcient Solution
void CycleSort(int arr[],int n)
{
	for(int cs=0;cs<n-1;cs++)
	{
		int item=arr[cs];
		int pos=cs;

		for(int i=cs+1;i<n;i++)
			if(arr[i]<item)
				pos++;
		swap(item,arr[pos]);

		while(cs!=pos)
		{
			pos=cs;
			for(int i=cs+1;i<n;i++)
				if(arr[i]<item)
					pos++;
			swap(item,arr[pos]);
		}
	}
}

int main()
{
	int arr[]={10,20,50,40,30};
	int n=sizeof(arr)/sizeof(arr[0]);
	CycleSort(arr,n);

	for(int x:arr)
		cout<<x<<" ";
	
	
	return 0;
}