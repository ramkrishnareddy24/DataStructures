#include<iostream>
using namespace std;

int main()
{
	int count(0);
	int n;
	int a,b,c;
	cin>>n;
	while(n--)
	{
		cin>>a>>b>>c;
		if(a+b+c>=2)
		{
			count++;
		}


	}
	cout<<count;


	return 0;    
}
