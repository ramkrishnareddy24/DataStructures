#include<iostream>
#include<unordered_map>
using namespace std;

//Naive Solution
void countFreq(int arr[],int n)
{
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
		if(flag==true) continue;

		int freq=1;
		for(int j=i+1;j<n;i++)
			if(arr[j]==arr[i])
				freq++;
		cout<<arr[i]<<" "<<freq<<endl;
	}
}

//Efficient Solution
void CountFreq(int arr[],int n)
{
	unordered_map<int,int> m;

	for(int i=0;i<n;i++)
		m[arr[i]]++;

	for(auto x:m)
		cout<<x.first<<" "<<x.second<<endl;
}

int main()
{
	int arr[]={5,5,5,10,10,20};
	int n=sizeof(arr)/sizeof(arr[0]);
	// countFreq(arr,n);
	CountFreq(arr,n);
	return 0;
}