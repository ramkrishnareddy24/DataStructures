#include<iostream>
#include<cstring>
using namespace std;

int isPal(string str,int s,int e)
{
	//if(s==e) return 1;
	//if(s>e) return 1;
	if(str[s]!=str[e])
		return 0;
	return isPal(str,s+1,e-1);
}

int main()
{
	string str;
	int s=0,e=str.length()-1;
	
	cin>>str;

	cout<<isPal(str,s,e);

}