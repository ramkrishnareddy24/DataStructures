#include<iostream>
using namespace std;

void AntonDanik(char s[],int n)
{
	int count1=0,count2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A')
			count1++;
		if(s[i]=='D')
			count2++;
	}
	if(count1>count2)
		cout<<"Anton";
	else if(count2>count1)
		cout<<"Danik";
	else
		cout<<"Friendship";

}

int main()
{
	int n;
	cin>>n;
	char s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}

	AntonDanik(s,n);

	return 0;
}