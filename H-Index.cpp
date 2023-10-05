#include<bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations)
{
	int n = citations.size();
	vector<int> count(n+1,0);

	for(int citation:citations){
		if(citation >= n)
			count[n]++;
		else
			count[citation]++;
	}

	int papers = 0;
	for(int i=n;i>=0;i--){
		papers+=count[i];
		if(papers>=i)
			return i;
	}
	return 0;
}

int HIndex(vector<int>& citations)
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	int n = citations.size();
	int low = 0,high = n-1,mid;

	while(low<=high)
	{
		mid = low+(high-low)/2;

		if(citations[mid]==(n-mid))
			return citations[mid];
		else if((n-mid)<citations[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	return n-low;
}

int main()
{
	vector<int> citations = {1,3,1};
	int ans = HIndex(citations);
	cout<<ans;

	return 0;
}