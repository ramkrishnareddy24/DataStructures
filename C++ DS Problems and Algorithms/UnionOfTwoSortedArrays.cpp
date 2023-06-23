#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void unionOfTwoArrays(int a[],int b[],int m,int n)
{
	int c[m+n];
	for(int i=0;i<m;i++)
		c[i]=a[i];
	for(int i=0;i<n;i++)
		c[m+i]=b[i];

	sort(c,c+m+n);

	for(int i=0;i<m+n;i++)
	{
		if(i==0 || c[i]!=c[i-1])
			cout<<c[i]<<" ";
	}
}

//Efficient Solution
void Union(int a[],int b[],int m,int n)
{
	int i=0,j=0;
	while(i<m && j<n)
	{
		if(i>0 && a[i-1]==a[i])
		{
			i++;
			continue;
		}
		if(j>0 && b[j-1]==b[j])
		{
			j++;
			continue;
		}

		if(a[i]<b[j])
		{
			cout<<a[i]<<" ";
			i++;
		}
		else if(b[j]<a[i])
		{
			cout<<b[j]<<" ";
			j++;
		}
		else
		{
			cout<<a[i]<<" ";
			i++;
			j++;
		}
	}
	while(i<m)
	{
		if(i==0 || a[i]!=a[i-1])
		{
			cout<<a[i]<<" ";
			i++;
		}
	}
	while(j<n)
	{
		if(j==0 || b[j]!=b[j-1])
		{
			cout<<b[j]<<" ";
			j++;
		}
	}
}



int main()
{
	int a[]={1,2,3,4,5};
	int b[]={1,2,3};
	int m=sizeof(a)/sizeof(a[0]);
	int n=sizeof(b)/sizeof(b[0]);

	unionOfTwoArrays(a,b,m,n);
	cout<<endl;
	Union(a,b,m,n);
	return 0;
}