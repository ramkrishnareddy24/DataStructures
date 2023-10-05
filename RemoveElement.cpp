#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums,int val){
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            nums[count++]=nums[i];
        }
    }
    return count;
}

int main()
{
    vector<int> nums1 = {0,1,2,2,3,0,4,2};
    int val = 2;
    int k = removeElement(nums1,val);
    cout<<k;
    return 0;
}