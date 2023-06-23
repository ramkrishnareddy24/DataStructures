/*In Tail-Recursive function last call in the function must
be recursive so that function runs faster.*/
#include<iostream>
using namespace std;

int fact(int n,int k=1)
{
	if(n==0)
		return k;
	return fact(n-1,n*k);  //Tail-Recursive call

}

int main()
{
	int n;
	cin>>n;
	cout<<fact(n);
}
