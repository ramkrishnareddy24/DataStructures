#include<bits/stdc++.h>
using namespace std;

//Efficient Solution
int minNumber(int arr[], int low, int high)
{
        // Your code here
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]<arr[mid-1] || high==low)
            return arr[mid];
            else
            if(arr[mid]>arr[high])
                low=mid+1;
            else if(arr[mid]<arr[high])
                high=mid-1;
        }
}

int main()
{
	int arr[]={3,4,5,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int low=0;
	int high=n-1;
	cout<<minNumber(arr,low,high);
	return 0;
}
