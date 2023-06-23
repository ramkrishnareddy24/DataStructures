#include<bits/stdc++.h>
using namespace std;

void rotateImage(vector<vector<int>>& m)
{
	int n=m.size();

	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			swap(m[i][j],m[j][i]);

	for(int i=0;i<n;i++)
		reverse(m[i].begin(),m[i].end());
}

int main()
{
	vector<vector<int>> v{{1,2,3},{4,5,6},{7,8,9}};
	rotateImage(v);

	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
		

	return 0;
}