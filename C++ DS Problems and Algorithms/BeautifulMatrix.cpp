#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a[6][6],x,y,i,j,ans;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			{
				x=i+1;
				y=j+1;
			}
		}
	}

	ans=abs(x-3)+abs(y-3);
	cout<<ans;

	return 0;
}