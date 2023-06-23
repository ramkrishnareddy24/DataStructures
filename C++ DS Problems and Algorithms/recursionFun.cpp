#include<bits/stdc++.h>
using namespace std;

void fun(int n)
{
	if(n<1)
		return;
	else
	{
		cout<<n<<" ";
		fun(n-1);
		cout<<n<<" ";
	}
}

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}

int fibonacci(int n)
{
	if(n==0)
		return 0;
	else
		if(n==1)
			return 1;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

void print1ToN(int n)
{
	if(n<1)
		return;
	else
		print1ToN(n-1);
		cout<<n<<" ";	//it prints 1 to N		
}

void print1ToN_tailRec(int n,int k)
{
	if(n<1)
		return;
	else
		cout<<k<<" ";
	print1ToN_tailRec(n-1,k+1);
}

//Tail Recursive
void printNTo1(int n)
{
	if(n<1)
		return;
	else
		cout<<n<<" ";	//prints N to 1
		printNTo1(n-1);
}

int main()
{
	fun(3);
	cout<<endl<<fact(0)<<endl;
	cout<<fibonacci(4)<<endl;
	print1ToN(5);
	cout<<endl;
	printNTo1(5);
	cout<<endl;
	print1ToN_tailRec(5,1);
}