#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void waveArray(vector<int>&arr,int n)
	{
		// vector<int> v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i+=2)
        swap(arr[i],arr[i+1]);  
	}
};

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		Solution ob;
		ob.waveArray(a,n);

		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}