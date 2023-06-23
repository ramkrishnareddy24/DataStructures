#include<bits/stdc++.h>
using namespace std;

int searchInsert(int nums[],int n, int target) {
        int low=0,high=n-1;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;

            if(nums[mid]==target)
                return mid;

            if(target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return nums[mid]>target?mid:mid+1;
}


int main()
{
    // string num1="10",num2="10";
    // cout<<addStrings(num1,num2);
    int arr[]={1,3,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<searchInsert(arr,n,7);

    



    return 0;
}