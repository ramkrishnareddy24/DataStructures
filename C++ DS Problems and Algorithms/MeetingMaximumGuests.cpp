#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int maxGuests(int arr[],int dep[],int n)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		int curr=1;
		for(int j=i+1;j<n;j++)
			if((arr[i]>=arr[j] && arr[i]<=dep[j]) || (arr[j]>=arr[i] && arr[j]<=dep[i]))
				curr++;
		res=max(res,curr);
	}
	return res;
}

//Efficient Solution
//also Known as Minimum Platform Problem
int MaxGuests(int arr[],int dep[],int n)
{
	sort(arr,arr+n);
	sort(dep,dep+n);

	int i=1,j=0,curr=1,res=1;
	while(i<n && j<n)
	{
		if(arr[i]<=dep[j])
		{
			i++;
			curr++;
		}
		else
		{
			j++;
			curr--;
		}
		res=max(res,curr);
	}
	return res;
}

int main()
{
	int arr[]={900,600,700};
	int dep[]={1000,800,730};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<maxGuests(arr,dep,n)<<endl;
	cout<<MaxGuests(arr,dep,n)<<endl;
	return 0;
}