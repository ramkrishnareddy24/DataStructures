#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int left = m-1;
        // int right = 0;

        // while(left>=0 && right<n){
        //   if(nums1[left]>0 && nums2[right]>0 && nums1[left]<nums2[right]){
        //     swap(nums1[left],nums2[right]);
        //     left--;
        //     right++;
        //   }
        //   else{
        //     break;
        //   }
        // }
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());   


        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = nums1.size();
    int n = nums2.size(); 

    merge(nums1,m,nums2,n);

    for(auto it:nums1){
        cout<<it<<" ";
    }
    for(auto it:nums2){
        cout<<it<<" ";
    }
    return 0;
}