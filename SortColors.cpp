#include<bits/stdc++.h>
using namespace std;

void sort0s1s2s(vector<int>& nums)
{
	int n=nums.size();
	int low=0,mid=0,high=n-1;

	while(mid<=high)
	{
		switch(nums[mid])
		{
			case 0:swap(nums[low],nums[mid]);
				low++;
				mid++;
				break;
			case 1:mid++;
				break;
			case 2:swap(nums[mid],nums[high]);
				high--;
				break;
		}
	}
}

int main()
{
	vector<int> v={2,2,1,0,1,2,1,0,0};
	sort0s1s2s(v);

	for(auto x:v)
		cout<<x<<" ";

	return 0;
}