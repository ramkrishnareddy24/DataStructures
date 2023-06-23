#include<iostream>
using namespace std;

int PrintNumber(int n)
{
	if(n<1)
		return n;
	
	PrintNumber(n-1);
	cout<<n<<" ";

}

int main()
{
	int n;
	cin>>n;

	PrintNumber(n);
}