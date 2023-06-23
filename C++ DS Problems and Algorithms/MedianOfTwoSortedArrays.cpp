#include<bits/stdc++.h>
using namespace std;

// Naive Solution
int median(int a1[],int a2[],int n1,int n2)
{
	int temp[n1+n2];
	for(int i=0;i<n1;i++)
		temp[i]=a1[i];
	for(int i=0;i<n2;i++)
		temp[n1+i]=a2[i];

	sort(temp,temp+(n1+n2));

	int med=0;
	int low=0,high=(n1+n2)-1;
	if(n1+n2%2==0)
	{
		int mid=(low+high)/2;
		med=(temp[mid]+temp[mid+1])/2;
	}
	else
	{
		int mid=(low+high)/2;
		med=temp[mid];
	}
	return med;
}

//Efficient Solution
double medianOfSortedArrays(int a1[],int a2[],int n1,int n2)
{
	int begin1=0,end1=n1;
	if(n2<n1) return medianOfSortedArrays(a2,a1,n2,n1);
	while(begin1<=end1)
	{
		int i1 = (begin1+end1)/2;
		int i2 = (n1+n2+1)/2-i1;

		int min1 = (i1==n1)?INT_MAX:a1[i1];
		int max1 = (i1==0)?INT_MIN:a1[i1-1];
		int min2 = (i2==n2)?INT_MAX:a2[i2];
		int max2 = (i2==0)?INT_MIN:a2[i2-1];

		if(max1<=min2 && max2<=min1)
		{
			if((n1+n2)%2==0)
				return ((double)max(max1,max2)+min(min1,min2))/2.0;
			else
				return ((double)max(max1,max2));
		}
		else if(max1>min2)
			end1 = i1-1;
		else
			begin1 = i1+1;
	}
	return 0.0;
} 


int main()
{
	int a1[]={30,40,50,60};
	int a2[]={5,6,7,8,9};
	int n1=sizeof(a1)/sizeof(a1[0]);
	int n2=sizeof(a2)/sizeof(a2[0]);
	cout<<medianOfSortedArrays(a1,a2,n1,n2)<<endl;
	cout<<median(a1,a2,n1,n2);
	
	return 0;
}