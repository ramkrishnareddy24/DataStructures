#include<iostream>
using namespace std;

void Hulk(int n)
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++){
			if(i%2)
				cout<<"I Hate ";
			else
				cout<<"I Love ";
			if(i==n)
				cout<<"it";
			else
				cout<<" that ";
		}
	}
}

int main()
{
	int n;
	Hulk(n);
	return 0;
}