#include<iostream>
#include<cstring>
using namespace std;

int luckyNumber(char n[])
{
	int count1=0,count2=0;
	for(int i=0;i<strlen(n);i++)
	{
		if(n[i]=='4')
			count1++;
		if(n[i]=='7')
			count2++;
	}
	
	if(count1+count2==4 || count1+count2==7)
		cout<<"YES";
	else
		cout<<"NO";

	return 0;
}

int main()
{
	char n[100];
	cin>>n;

	luckyNumber(n);

}