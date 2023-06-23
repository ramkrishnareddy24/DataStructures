#include<iostream>
using namespace std;

int FindIndex(int arr[],int n,int x)
{
	int ans;
	if(n==0)
		return -1;
	if(arr[0]==x)
		return 0;

	ans=FindIndex(arr+1,n-1,x);

	if(ans==-1)
		return -1;
	else
		return ans+1;

}

int main()
{
	int arr[100];
	int n,x;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>x;

	cout<<FindIndex(arr,n,x);

	return 0;
}