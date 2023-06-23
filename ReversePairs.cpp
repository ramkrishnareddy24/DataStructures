#include<bits/stdc++.h>
using namespace std;

int reversePairs(vector<int> arr)
{
	int pairs=0;
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>2*arr[j])
				pairs++;
		}
	}
	return pairs;
}

int main()
{

}