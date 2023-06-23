#include<bits/stdc++.h>
using namespace std;

void printName(int i,int n)
{
	if(i>n)
		return;
	cout<<"Ram"<<endl;
	
	printName(i+1,n);
}

void printLinearly(int i,int n)
{
	if(i>n)
		return;
	cout<<i<<" ";
	printLinearly(i+1,n);
}

void printLinearlyRev(int i,int n)
{
	if(i<1)
		return;
	cout<<i<<" ";
	printLinearlyRev(i-1,n);
}

void print1toNBackTrack(int i,int n)
{
	if(i<1)
		return;
	print1toNBackTrack(i-1,n);
	cout<<i<<" ";
}

void printNto1BackTrack(int i,int n)
{
	if(i>n)
		return;
	printNto1BackTrack(i+1,n);
	cout<<i<<" ";
}

void sumParameterised(int i,int sum)
{
	if(i<1)
	{
		cout<<sum<<" ";
		return;
	}
	sumParameterised(i-1,sum+i);
}

int sumFunctional(int n)
{
	if(n==0)
		return 0;
	return n+sumFunctional(n-1);
}

void reverseArr(int arr[],int n,int l,int r)
{
	if(l>=r)
		return;
	swap(arr[l],arr[r]);
	reverseArr(arr,n,l+1,r-1);
}

void reverseSinglePtr(int arr[],int n,int i)
{
	if(i>=n/2) return;
	swap(arr[i],arr[n-i-1]);
	reverseSinglePtr(arr,n,i+1);
}

bool palindromeRecursion(string str,int i)
{
	int n=str.length();
	if(i>=n/2) return true;
	if(str[i]!=str[n-i-1]) return false;
	return palindromeRecursion(str,i+1);
}

int main()
{
	// int n=5;
	// printName(1,n);
	// printLinearly(1,n);
	// printLinearlyRev(n,n);
	// print1toNBackTrack(n,n);
	// printNto1BackTrack(1,n);
	// sumParameterised(5,0);
	// cout<<sumFunctional(5);

	// int arr[]={1,2,3,4,5};
	// int n1=sizeof(arr)/sizeof(int);
	// reverseArr(arr,n1,0,n1-1);
	// for(int i=0;i<n1;i++)
	// 	cout<<arr[i]<<" ";

	// reverseSinglePtr(arr,n1,0);
	// for(int i=0;i<n1;i++)
	// 	cout<<arr[i]<<" ";

	string str="MAMM";
	cout<<palindromeRecursion(str,0);

	return 0;
}