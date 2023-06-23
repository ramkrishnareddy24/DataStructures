#include<iostream>
#include<cstring>
using namespace std;

void SubString(string str,string curr="",int index=0)
{
	int n=str.length();
	if(index==n)
	 return;
		cout<<curr<<endl;
	

	 SubString(str,curr+str[index],index+1);
	 SubString(str,curr,index+1);

	
}

int main()
{
	string str="abc";
	SubString(str);
}