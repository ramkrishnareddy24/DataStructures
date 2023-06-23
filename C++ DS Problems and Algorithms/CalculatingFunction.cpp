#include<iostream>
using namespace std;

int calculation(int n)
{
	int res=1;
	for(int i=1;i<=n;i++)
	{
		res=-res+(i+1);
	}
	cout<<res;
}

int main()
{
	int n;
	cin>>n;

	calculation(n);
}