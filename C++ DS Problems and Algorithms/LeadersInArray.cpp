#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void leadersArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=i+1;j<n;j++)
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
void LeadersArray(int arr[],int n)
{
	vector<int> v;
	int currldr=arr[n-1];
	v.push_back(currldr);

	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>=currldr)
		{
			currldr=arr[i];
			v.push_back(currldr);
		}
	}
	reverse(v.begin(),v.end());
	// return v;

	for(auto it:v)
		cout<<it<<" ";
}


int main()
{
	int arr[]={16,17,4,3,5,2};
	int n=sizeof(arr)/sizeof(int);
	leadersArray(arr,n);cout<<endl;
	LeadersArray(arr,n);

	return 0;
}