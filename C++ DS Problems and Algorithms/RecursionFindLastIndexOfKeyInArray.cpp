#include<iostream>
using namespace std;

int FindLastIndex(int arr[],int n,int x)
{
	int ans;
	if(n==0)
		return -1;

	ans=FindLastIndex(arr+1,n-1,x);

	if(arr[0]==x)
		return 0;

	if(ans==-1)
		return -1;
	else
		return ans+1;

}

int main()
{
	int arr[10];
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int x;
	cin>>x;

	cout<<FindLastIndex(arr,n,x);
}