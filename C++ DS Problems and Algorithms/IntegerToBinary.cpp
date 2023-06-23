#include<bits/stdc++.h>
using namespace std;

void IntegerToBinary(int n)
{
	int binary[32];
	int i=0;

	while(n>0)
	{
		binary[i]=n%2;
		n=n/2;
		i++;
	}

	for(int j=i-1;j>=0;j--)
		cout<<binary[j];
}

int main()
{
	int n=7;
	IntegerToBinary(n);
	
	return 0;
}
