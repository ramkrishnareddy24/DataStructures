#include<iostream>
#include<bits/stdc++.h>
#define range 255
using namespace std;

string countingSort(string arr)
{
	char k=range+1;
	int n=arr.length();

	int count[k];
	for(int i=0;i<k;i++)
		count[i]=0;
	for(int i=0;i<n;i++)
		count[arr[i]]++;

	for(int i=0;i<k;i++)
		count[i]=count[i-1]+count[i];

	char output[n];
	for(int i=n;i>=0;i--)
	{
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}

	for(int i=0;i<n;i++)
		arr[i]=output[i];
}

int main()
{
	string s="eadbc";
	countingSort(s);

	for(int i=0;i<s.length();i++)
		cout<<s[i];

	
}