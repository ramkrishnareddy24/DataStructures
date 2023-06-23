#include<iostream>
#include<unordered_map>
using namespace std;

//Naive Solution
int maxCommon(int arr1[],int arr2[],int n)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		int sum1=0,sum2=0;
		for(int j=i;j<n;j++)
		{
			sum1+=arr1[j];
			sum2+=arr2[j];

			if(sum1==sum2)
				res=max(res,j-i+1);
		}
	}
	return res;
}

//Efficient Solution
int MaxCommon(int arr1[],int arr2[],int n)
{
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=arr1[i]-arr2[i];

	unordered_map<int,int> m;
	int res=0;
	int pref_sum=0;

	for(int i=0;i<n;i++)
	{
		pref_sum+=arr[i];

		if(m.find(pref_sum)==m.end())
			m.insert({pref_sum,i});
		if(m.find(pref_sum)!=m.end())
			res=max(res,i-m[pref_sum]);
		else
			res=m[pref_sum];
	}
	return res;
}

int main()
{
	int arr1[]={0,1,0,0,0,0};
	int arr2[]={1,0,1,0,0,1};
	int n=sizeof(arr1)/sizeof(arr1[0]);
	cout<<maxCommon(arr1,arr2,n)<<" ";
	cout<<MaxCommon(arr1,arr2,n);
	return 0;
}