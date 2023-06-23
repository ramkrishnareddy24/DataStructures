#include<bits/stdc++.h>
using namespace std;

// Binary Search Iterative
int binarySearch(int arr[],int n,int x)
{
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		int mid = (low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(arr[mid]<x)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

// binary Search Recursive
int binarySearchRecursive(int arr[],int low,int high,int x)
{
	while(low<=high)
	{
		int mid=(low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(arr[mid]<x)
			return binarySearchRecursive(arr,mid+1,high,x);
		else
			return binarySearchRecursive(arr,low,mid-1,x);
	}
	return -1;
}

// firstOccurence in Sorted Array Recursive
int firstOccurenceRecursive(int arr[],int low,int high,int x)
{
	if(low>high) return -1;

	int mid = (low+high)/2;
	if(arr[mid]<x)
		return firstOccurenceRecursive(arr,mid+1,high,x);
	else if(arr[mid]>x)
		return firstOccurenceRecursive(arr,low,mid-1,x);
	else
	{
		if(mid==0 || arr[mid]!=arr[mid-1])
			return mid;
		else
			high=mid-1;
	}
}

// firstOccurence in Sorted Array Iterative
int firstOccurenceIterative(int arr[],int n,int x)
{
	int low=0,high=n-1;

	if(low>high) return -1;

	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]<x)
			low=mid+1;
		else if(arr[mid]>x)
			high=mid-1;
		else
		{
			if(mid==0 || arr[mid]!=arr[mid-1])
				return mid;
			else
				high=mid-1;
		}
	}	
}

// last Occurence Recursive
int lastOccurenceRecursive(int arr[],int low,int high,int x)
{
	if(low>high) return -1;

	int mid=(low+high)/2;

	if(arr[mid]<x)
		return lastOccurenceRecursive(arr,mid+1,high,x);
	else if(arr[mid]>x)
		return lastOccurenceRecursive(arr,low,mid-1,x);
	else
	{
		if(mid==high || arr[mid]!=arr[mid+1])
			return mid;
		else
			low = mid+1;
	}
}

// last Occurence Iterative
int lastOccurenceIterative(int arr[],int n,int x)
{
	int low=0,high=n-1;
	if(low>high) return -1;

	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid]<x)
			low = mid+1;
		if(arr[mid]>x)
			high = mid-1;
		else
		{
			if(mid==n-1 || arr[mid]!=arr[mid+1])
				return mid;
			else
				low = mid+1;
		}		
	}
}

// Count Occurences
int countOccurence(int arr[],int n,int x)
{
	int firstOcc = firstOccurenceIterative(arr,n,x);
	int lastOcc = lastOccurenceIterative(arr,n,x);

	if(firstOcc == -1)
		return 0;
	return (lastOcc-firstOcc+1);
}

// Count 1s in DescSorted Binary Array
int countOnes(bool arr[],int n)
{
	int low=0,high=n-1;

	while(low<=high)
	{
		int mid = (low+high)/2;

		if(arr[mid]<1)
			high = mid-1;
		else if(arr[mid]>1)
			low=mid+1;
		else
		{
			if(mid==n-1 || arr[mid+1]!=1)
				return mid+1;
			else
				low = mid+1;
		}
	}
}

// Square Root of an Number
int squareRoot(int x)
{
	int low=0,high=x;
	int ans=-1;

	while(low<=high)
	{
		int mid=(low+high)/2;
		int midSq=mid*mid;

		if(midSq>x)
			high=mid-1;
		else
		{
			low=mid+1;
			ans=mid;
		}
	}
	return ans;
}

// Peak Element
int peakElement(int arr[],int n)
{
	int low=0,high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;
		if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
			return arr[mid];

		if(mid>0 && arr[mid-1]>=arr[mid])
			high=mid-1;
		else
			low=mid+1;
	}
}

// Search in Sorted and Rotated Array
int searchInSortedRotated(int arr[],int n,int x)
{
	int low=0,high=n-1;

	while(low<=high)
	{
		int mid = (low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(arr[mid]>arr[low])
		{
			if(x<arr[mid] && x>=arr[low])
				high=mid-1;
			else
				low=mid+1;
		}
		else if(arr[mid]<arr[high])
		{
			if(x>arr[mid] && x<=arr[high])
				low=mid+1;
			else
				high=mid-1;
		}
	}
}

//Leetcode Search in Sorted Rotated Array
 int search(vector<int>& nums, int target) {
        
        int low=0,high=nums.size()-1;
        // int res=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(target==nums[mid])
                return mid;
            
            if(nums[low]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[low])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else if(nums[mid]<nums[high])
            {
                if(target>=nums[mid] && target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }

// Two Pointer Approach
int twoPointerIsPair(int arr[],int n,int sum)
{
	int left=0,right=n-1;

	while(left<right)
	{
		if(arr[left]+arr[right]==sum)
			return true;
		if(arr[left]+arr[right]>sum)
			right--;
		else
			left++;
	}
	return false;
}

// Majority Element
int majorityElement(int arr[],int n)
{
	int count=1;
	int res=0;

	for(int i=1;i<n;i++)
	{
		if(arr[res]==arr[i])
			count++;
		else
			count--;

		if(count==0)
		{
			count=1;
			res=i;
		}
	}

	count=0;
	for(int i=0;i<n;i++)
		if(arr[res]==arr[i])
			count++;
	if(count<=n/2)
		res=-1;

	return arr[res];
}

// Median of two sorted Arrays
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
	int arr[] = {1,7,8,8,8,8,8,8};
	int n=sizeof(arr)/sizeof(int);

	cout<<"binarySearch :"<<binarySearch(arr,n,7)<<endl;
	int low=0,high=n-1;
	cout<<"binarySearchRecursive :"<<binarySearchRecursive(arr,low,high,7)<<endl;

	cout<<"firstOccurenceRecursive :"<<firstOccurenceRecursive(arr,low,high,8)<<endl;
	cout<<"firstOccurenceIterative :"<<firstOccurenceIterative(arr,n,8)<<endl; 

	cout<<"lastOccurenceRecursive :"<<lastOccurenceRecursive(arr,low,high,8)<<endl;
	cout<<"lastOccurenceIterative :"<<lastOccurenceIterative(arr,n,8)<<endl;

	cout<<"countOccurence :"<<countOccurence(arr,n,8)<<endl;

	bool brr[] = {1,1,1,1,0,0,0};
	int m = sizeof(brr)/sizeof(bool);
	cout<<"countOnes :"<<countOnes(brr,m)<<endl;

	cout<<"Square Root :"<<squareRoot(25)<<endl;

	int arr2[] = {5,20,40,30,20,50,60};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	cout<<"PeakElement :"<<peakElement(arr2,n2)<<endl;

	int arr3[]={100,200,400,100,10,20};
	int n3=sizeof(arr3)/sizeof(arr3[0]);
	cout<<"searchInSortedRotated :"<<searchInSortedRotated(arr3,n3,200)<<endl;

	int arr4[]={2,4,8,9,11,12,20,30};
	int n4=sizeof(arr4)/sizeof(arr4[0]);
	cout<<"Two Pointer Approach Sum :"<<twoPointerIsPair(arr4,n4,23)<<endl;

	int arr5[] = { 1, 1, 2, 1, 3, 5, 1 };
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout<<"Majority Element :"<<majorityElement(arr5,n5)<<endl;

    int a1[]={1,2}; int s1=sizeof(a1)/sizeof(in
    	t);
    int a2[]={3,4}; int s2=sizeof(a2)/sizeof(int);
    cout<<"medianOfSortedArrays :"<<medianOfSortedArrays(a1,a2,s1,s2)<<endl;
	return 0;
}