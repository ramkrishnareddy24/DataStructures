#include<bits/stdc++.h>
using namespace std;

void sortStrings(vector<string>& v)
{
	int n=v.size();

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(v[i].compare(v[j])>0)
			{
				swap(v[i],v[j]);
			}
		}
	}
}

int main()
{
	vector<string> v={"bat","batman","apple"};

	sortStrings(v);
	for(auto x:v)
		cout<<x<<endl;
	return 0;
}