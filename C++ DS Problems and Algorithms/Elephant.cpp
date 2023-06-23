#include<iostream>
using namespace std;

int elephant(int x)
{
	int count=0;
	while(x!=0)
	{
		if(x>=5){
			x=x-5;
			count++;
		}
		else if(x>=4){
			x=x-4;
			count++;
		}
		else if(x>=3){
			x=x-3;
			count++;
		}
		else if(x>=2){
			x=x-2;
			count++;
		}
		else{
			x=x-1;
			count++;
		}
	}
	cout<<count;
}

int main()
{
	int x;
	cin>>x;
	elephant(x);
}