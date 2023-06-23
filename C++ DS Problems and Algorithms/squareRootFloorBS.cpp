#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int SqRoot(int x)
{
	int i=1;
	while(i*i<=x)
	{
		i++;
	}
	return (i-1);
}

//Efficient Solution
int sqRoot(int x)
{
	int low=0;
	int high=x;
	int ans=-1;

	while(low<=high)
	{
		int mid=(low+high)/2;
		int midSq=mid*mid;

		if(midSq==x)
			return mid;

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


int main()
{
	cout<<SqRoot(16)<<" ";
	cout<<sqRoot(25);
	return 0;
}