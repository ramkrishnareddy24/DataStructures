#include<bits/stdc++.h>
#include<cstring>
using namespace std;

//Efficient Solution
string reverse(string s)
{
	int n=s.length();
	int low=0;
	int high=n-1;

	while(low<high)
	{
		swap(s[low],s[high]);
		low++;
		high--;
	}
	return s;
}

//Efficient Solution
bool palindrome(string str)
{
	int low=0;
	int high=str.length()-1;
	transform(str.begin(),str.end(),str.begin(),::toupper);
	cout<<str<<endl;
	while(low<=high)
	{
		if(str[low]!=str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

int main()
{
	string s="malayalam";
	cout<<reverse(s)<<endl;
	cout<<palindrome(s);
}