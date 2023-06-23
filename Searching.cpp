#include<bits/stdc++.h>
using namespace std;

// Iterative
int binarySearch(int arr[],int n,int x)
{
	int low=0,high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(x<arr[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

// Recursive
int BinarySearch(int arr[],int low,int high,int x)
{
	while(low<=high)
	{
		int mid=(low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(x<arr[mid])
			return BinarySearch(arr,low,mid-1,x);
		else
			return BinarySearch(arr,mid+1,high,x);
	}
	return -1;
}

// Recursive
int firstOccurence(int arr[],int low,int high,int x)
{
	while(low<=high)
	{
		int mid = (low+high)/2;

		if(x<arr[mid])
			return firstOccurence(arr,low,mid-1,x);
		else if(x>arr[mid])
			return firstOccurence(arr,mid+1,high,x);
		else
		{
			if(mid==0 || arr[mid]!=arr[mid-1])
				return mid;
			else
				high=mid-1;
		}
	}
}

// Iterative
int FisrtOccurence(int arr[],int n,int x)
{
	int low=0,high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;

		if(x<arr[mid])
			high=mid-1;
		else if(x>arr[mid])
			low=mid+1;
		else
		{
			if(mid==0 || arr[mid]!=arr[mid-1])
				return mid;
			else
				high=mid-1;
		}
	}
}

// Recursive
int lastOccurence(int arr[],int low,int high,int x)
{
	while(low<=high)
	{
		int mid = (low+high)/2;

		if(x<arr[mid])
			return lastOccurence(arr,low,mid-1,x);
		else if(x>arr[mid])
			return lastOccurence(arr,mid+1,high,x);
		else
		{
			if(mid==high || arr[mid]!=arr[mid+1])
				return mid;
			else
				low=mid+1;
		}
	}
}

// Iterative
int LastOccurence(int arr[],int n,int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;

		if(x<arr[mid])
			high=mid-1;
		else if(x>arr[mid])
			low=mid+1;
		else
		{
			if(mid==n-1 || arr[mid]!=arr[mid+1])
				return mid;
			else
				low=mid+1;
		}
	}
}

int countOccurences(int arr[],int n,int x)
{
	int firstOcc = FisrtOccurence(arr,n,x);
	int lastOcc = LastOccurence(arr,n,x);

	if(firstOcc==-1)
		return -1;
	return (lastOcc-firstOcc+1);
}

int countOnes(int arr[],int n)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]<1)
			high=mid-1;
		else if(arr[mid]>=1)
			low=mid+1;
		else
		{
			if(mid==n-1 || arr[mid+1]!=1)
				return mid+1;
			else
				low=mid+1;
		}
	}
}

int SquareRoot(int x)
{
	int low=0,high=x;
	int ans=-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		int midSq=mid*mid;

		if(x<midSq)
			high=mid-1;
		else
		{
			low=mid+1;
			ans=mid;
		}
	}
	return ans;
}

int peakElement(int arr[],int n)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;

		if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
			return arr[mid];

		if(mid>0 && arr[mid-1]>arr[mid])
			high=mid-1;
		else
			low=mid+1;
	}
}

int searchInSortedRotatedArray(int arr[],int n,int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(arr[mid]>arr[low])
		{
			if(x<arr[mid] && x>arr[low])
				high=mid-1;
			else
				low=mid+1;
		}
		else if(arr[mid]<arr[high])
		{
			if(x>arr[mid] && x<arr[high])
				low=mid+1;
			else
				high=mid-1;
		}
	}
}

int twoPointer(int arr[],int n,int sum)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		// int mid=(low+high)/2;

		if(arr[low]+arr[high]==sum)
			return true;

		if(arr[low]+arr[high]>sum)
			high--;
		else
			low++;
	}
	return false;
}

// Median of Sorted Arrays using MergeSort
double median(int a[],int m,int b[],int n)
{
	vector<int> v;
	int i=0,j=0;
	while(i<m && j<n)
	{
		if(a[i]<=b[j])
			v.push_back(a[i++]);
		else
			v.push_back(b[j++]);
	}

	while(i<m) v.push_back(a[i++]);
	while(j<n) v.push_back(b[j++]);

	int low=0,high=v.size();
	int median=(low+high)/2;
	if(v.size()%2!=0)
	{
		return v[median];
	}
	else
	{
		 double med = (double)(v[median]+v[median-1])/2;
		 return med;
	}
}

// Median of Two Sorted Arrays
double Median(int a1[],int a2[],int n1,int n2)
{
	int begin1=0,end1=n1;
	if(n2<n1) return Median(a2,a1,n2,n1);

	while(begin1<=end1)
	{
		int i1=(begin1+end1)/2;
		int i2=(n1+n2+1)/2-i1;

		int min1=(i1==n1)?INT_MAX:a1[i1];
		int max1=(i1==0)?INT_MIN:a1[i1-1];
		int min2=(i2==n2)?INT_MAX:a2[i2];
		int max2=(i2==0)?INT_MIN:a2[i2-1];

		if(max1<=min2 && max2<=min1)
		{
			if((n1+n2)%2==0)
			{
				return (double)(min(min1,min2)+max(max1,max2))/2.0;
			}
			else
			{
				return (double)(max(max1,max2));
			}
		}
		else if(max1>min2)
			end1=i1-1;
		else
			begin1=i1+1;
	}
}

int main()
{
	int arr2[] = {5,20,40,30,20,50,60};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	cout<<"PeakElement :"<<peakElement(arr2,n2)<<endl;

	int brr[] = {1,1,1,1,0,0,0};
	int m = sizeof(brr)/sizeof(int);
	cout<<"countOnes :"<<countOnes(brr,m)<<endl;

	int a1[]={1,2}; int s1=sizeof(a1)/sizeof(int);
    int a2[]={3,4}; int s2=sizeof(a2)/sizeof(int);
    cout<<"medianOfSortedArrays :"<<Median(a1,a2,s1,s2)<<endl;
}