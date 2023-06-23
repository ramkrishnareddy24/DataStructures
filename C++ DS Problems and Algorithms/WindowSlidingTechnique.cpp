#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int slidingWindow(int arr[],int n,int k)
{
	int max_sum=INT_MIN;
	for(int i=0;i+k-1<n;i++)
	{
		int sum=0;
		for(int j=0;j<k;j++)
			sum+=arr[i+j];
		max_sum=max(sum,max_sum);
	}
	return max_sum;
}

//Efficient Solution
int SlidingWindow(int arr[],int n,int k)
{
	int curr_sum=0;
	for(int i=0;i<k;i++)
		curr_sum+=arr[i];

	int max_sum=curr_sum;
	for(int i=k;i<n;i++)
	{
		curr_sum+=(arr[i]-arr[i-k]);
		max_sum=max(curr_sum,max_sum);
	}
	return max_sum;
}

//Efficient Solution //Similar Problem to checkwhether
//Given SUM is present in Array
bool isSubArrayPresentGivenSum(int arr[],int n,int k,int sum)
{
	
	int curr_sum=0;
	for(int i=0;i<k;i++)
		curr_sum+=arr[i];

	int max_sum=0;
	for(int i=k;i<n;i++)
	{
		curr_sum+=arr[i];
		max_sum=max(curr_sum,max_sum);
	}
	return max_sum;
}

//bool isSubSum
bool isSubSum(int arr[],int n,int sum)
{
	int curr_sum=arr[0];
	int s=0;
	for(int e=1;e<n;e++)
	{
		while(curr_sum>sum && s<e-1)
		{
			curr_sum-=arr[s];
			s++;
		}

		if(curr_sum==sum)
			return true;

		if(e<n)
			curr_sum+=arr[e];
	}
	return false;
}

//printing start and end index which makes the subArray sum
vector<int> isSubArraySum(int arr[],int n,int sum)
{
	vector<int> v;
	int curr_sum=arr[0];
	int s=0;
	for(int e=1;e<n;e++)
	{
		//clearing the prev-window
		while(curr_sum>sum && s<e-1)
		{
			curr_sum-=arr[s];
			s++;
		}

		if(curr_sum==sum)
		{
			v.push_back(s);
			v.push_back(e);
		}

		if(e<n)
			curr_sum+=arr[e];
	}
}

//Maximum of all sub arrays of size k
void maxOfAllSubArraysOfSizeK(int arr[],int n,int k)
{
	for(int i=0;i<=n-k;i++)
	{
		int curr_max=arr[i];
		for(int j=1;j<k;j++)
		{
			if(arr[i+j]>curr_max)
				curr_max=arr[i+j];
		}
		cout<<curr_max<<" ";
	}
}

void bonacciseries(long m,int n)
{
	//Assuming m>n
	int a[n]={0};
	a[m-1]=1;
	a[m]=1;

	//sliding Window 
	for(int i=m+1;i<n;i++)
		a[i]=2*a[i-1]-a[i-m-1];

	//printing numbers
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

int main()
{
	int arr[]={1,8,30,5,20,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	// cout<<slidingWindow(arr,n,3)<<" ";
	// cout<<SlidingWindow(arr,n,3)<<" ";
	// cout<<isSubArrayPresentGivenSum(arr,n,3,55)<<" ";
	// cout<<isSubSum(arr,n,55);
	// cout<<endl;
	// maxOfAllSubArraysOfSizeK(arr,n,3);cout<<endl;
	bonacciseries(2,10);
	return 0;
}