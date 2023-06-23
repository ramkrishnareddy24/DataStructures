#include<bits/stdc++.h>
using namespace std;

//where indexes begin from 0 to N
int josephus(int n,int k)
{
	if(n==1)
		return 0;
	else
		return (josephus(n-1,k)+k)%n;
} 

// call this Fun() where indexes begin from 1 to N
int MyJos(int n,int k)
{
	return Jos(n,k)+1;
}

int main()
{
	cout<<josephus(5,3)<<endl;
	cout<<MyJos(5,3);
}