#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x=3,y=6;
	cout<<(x&y)<<" ";	//bitwise AND
	cout<<(x|y)<<" ";	//bitwise OR
	cout<<(x^y)<<" ";	//bitwise XOR

	cout<<endl;

	int x1=3;
	cout<<(x1<<1)<<" ";		//leftshift by 1
	cout<<(x1<<2)<<" ";		//leftshift by 2
	int y1=4;
	cout<<(x1<<y1)<<" ";	//leftshift by 4

	cout<<endl;

	int x2=33;
	cout<<(x2>>1)<<" ";		//rightshift by 1
	cout<<(x2>>2)<<" ";		//rightshift by 2
	int y2=4;
	cout<<(x2>>y2)<<" ";	//rightshift by 4

	cout<<endl;
	unsigned int a=5;
	cout<<(~a)<<endl;

	int a1=5;
	cout<<(~a1)<<endl;

}