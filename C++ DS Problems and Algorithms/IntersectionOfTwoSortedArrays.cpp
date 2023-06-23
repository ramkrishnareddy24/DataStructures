#include<bits/stdc++.h>
using namespace std;

//Naive Solution
void intersection(int a[],int b[],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		if(i>0 && a[i-1]==a[i])
			continue;
		for(int j=0;j<n;j++)
			if(a[i]==b[j])
				cout<<a[i]<<" ";
	}
}

//Efficient Solution
void Intersection(int a[],int b[],int m,int n)
{
	int i=0,j=0;
	while(i<m && j<n)
	{
		if(i>0 && a[i-1]==a[i])
		{
			i++;
			continue;
		}
		if(a[i]<b[j])
			i++;
		else if(b[j]<a[i])
			j++;
		else
		{
			cout<<a[i]<<" ";
			i++; j++;
		}
	}
}

int main()
{
	int a[]={3,5,10,10,10,15,15,20};
	int b[]={5,10,10,15,30};
	int m=sizeof(a)/sizeof(a[0]);
	int n=sizeof(b)/sizeof(b[0]);

	intersection(a,b,m,n);
	cout<<endl;
	Intersection(a,b,m,n);

	return 0;
}