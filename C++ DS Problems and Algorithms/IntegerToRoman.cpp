#include<bits/stdc++.h>
using namespace std;

int value(int r)
{
	if(r=='I')
		return 1;
	if(r=='V')
		return 5;
	if(r=='X')
		return 10;
	if(r=='L')
		return 50;
	if(r=='C')
		return 100;
	if(r=='D')
		return 500;
	if(r=='M')
		return 1000;
	return -1;
}

int romanToDecimal(string& str)
{
	int res=0;
	for(int i=0;i<str.length();i++)
	{
		int s1=value(str[i]);

		if(i+1<str.length())
		{
			int s2=value(str[i+1]);

			if(s1>=s2)
			{
				res=res+s1;
			}
			else
			{
				res=res+s2-s1;
				i++;
			}
		}
		else
		{
			res=res+s1;
		}
	}
	return res;
}


int decimalToRoman(int number)
{
	int num[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string sym[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

	int i=12;
	while(number>0)
	{
		int div=number/num[i];
		number=number%num[i];

		while(div--)
		{
			cout<<sym[i];
		}
		i--;
	}
}

int main()
{
	string str = "XXIV";
    cout << "Integer form of Roman Numeral is "<< romanToDecimal(str) << endl;
    int num=24;
    cout << "Roman form of Number is ";decimalToRoman(num);

 
    return 0;
}