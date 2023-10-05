#include<bits/stdc++.h>
using namespace std;

int mostWater(vector<int>& height)
{
	int n = height.size();
	int left = 0, right = n-1;
	int water = 0;

	while(left < right)
	{
		int area  = 0;
		if(height[left]<height[right])
		{
			area = height[left]*(right-left);
			left++;
		}
		else
		{
			area = height[right]*(right-left);
			right--;
		}

		if(area>water)
			water = area;
	}
	return water;
}

int main()
{
	vector<int> height = {1,8,6,2,5,4,8,3,7};
	int water = mostWater(height);
	cout<<water;

	return 0;
}