#include<iostream>
#include<unordered_set>
using namespace std;

//Naive Solution
int unionOfArrays(int a[],int b[],int m,int n)
{
	int c[m+n];
	for(int i=0;i<m;i++)
		c[i]=a[i];
	for(int i=0;i<n;i++)
		c[m+i]=b[i];

	int res=0;
	for(int i=0;i<m+n;i++)
	{
		bool flag=false;
		for(int j=0;j<i;j++)
		{
			if(c[i]==c[j])
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			res++;
		}
	}
	return res;
}

//Efficient Solution
int Union(int a[],int b[],int m,int n)
{
	unordered_set<int> s;
	for(int i=0;i<m;i++)
		s.insert(a[i]);
	for(int i=0;i<n;i++)
		s.insert(b[i]);
	return s.size();
}

int main()
{
	int a[]={15,20,5,15};
	int b[]={15,15,15,20,10};
	int m=sizeof(a)/sizeof(a[0]);
	int n=sizeof(b)/sizeof(b[0]);

	cout<<Union(a,b,m,n);
	return 0;
}