#include<iostream>
using namespace std;


int print(int n)
{
	if(n==0)
		return 0;
	print(n-1);
	cout<<n<<" ";
}

int main()
{
	int n;
	cout<<"Enter Num"<<endl;
	cin>>n;
	cout<<print(n);
	
}