#include<bits/stdc++.h>
using namespace std;

int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long totalsum=0;
        long long count=0;
        
        for(auto x:nums)
            totalsum+=x;
        
        long long leftsum=0;
        for(int i=0;i<n-1;i++)
        {
            long long rightsum=0;
            leftsum+=nums[i];
            rightsum=totalsum-leftsum;
            
            if(leftsum>=rightsum)
                count++;
        }
        return count;
}

int main()
{
    vector<int> nums = {2,3,1,0};
    // int n = sizeof(nums)/sizeof(int);
    int res = waysToSplitArray(nums);
    cout<<res;
    
}