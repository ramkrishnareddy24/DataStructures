#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n,count=0;;
	cin>>n;
	string x;

	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x[1]=='+')
		{
			++count;
		}
		else
		{
			--count;
		}
	}

	cout<<count<<endl;


	return 0;
}