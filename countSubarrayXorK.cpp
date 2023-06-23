#include<bits/stdc++.h>
using namespace std;

int subarrayWithGivenXorK(vector<int> &A,int B)
{
	map<int,int> freq;
	int cnt=0;
	int xorr=0;

	for(auto it:A)
	{
		xorr=xorr^it;

		if(xorr==B)
			cnt++;

		if(freq.find(xorr^B)!=freq.end())
			cnt+=freq[xorr^B];
		freq[xorr]+=1;
	}
	return cnt;
}

int main()
{
	vector<int> v={4, 2, 2, 6, 4};
	int b=6;
	int res=subarrayWithGivenXorK(v,b);
	cout<<res;
	return 0;
}