#include<iostream>
#include<unordered_set>
using namespace std;

//Naive Solution
int countDistinct(int arr[],int n)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j]==arr[i])
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
			res++;
	}
	return res;
}

//Efficient Solution
int CountDistinct(int arr[],int n)
{
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);
	return s.size();
}

int main()
{
	int arr[]={15,12,13,12,13,13,18};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<countDistinct(arr,n)<<endl;
	cout<<CountDistinct(arr,n)<<endl;
	return 0;
}