#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int search(int arr[],int n,int x)
{
	for(int i=0;i<n;i++)
		if(arr[i]==x)
			return i;
}

//Efficient Solution
int searchInSortedRotatedArray(int arr[],int n,int x)
{
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;
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
	return -1;
}
	
//Recursive Solution Efficient O(logn)
    int search(int A[], int l, int h, int key){
    //complete the function here
       if(l>h)
       return -1;
    
            int mid=(l+h)/2;
            
            if(A[mid]==key)
            return mid;
            
            if(A[mid]>A[l])
            {
                if(key<A[mid] && key>=A[l])
                return search(A,l,mid-1,key);
                else
                return search(A,mid+1,h,key);
            }
            else
            {
                if(key>A[mid] && key<=A[h])
                return search(A,mid+1,h,key);
                else
                return search(A,l,mid-1,key);
            }
       
    }

int main()
{
	int arr[]={100,200,400,100,10,20};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<search(arr,n,10)<<" ";
	cout<<searchInSortedRotatedArray(arr,n,10);
}

