#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
	string vstr = "";
	for(int i=0;i<str.length();i++){
		if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9'))
			vstr+=str[i];
	}
	transform(vstr.begin(), vstr.end(), vstr.begin(), ::tolower);

	int lo = 0,hi = vstr.length()-1;
	while(lo<=hi){
		if(vstr[lo]!=vstr[hi]){
			return false;
		}
		lo++;
		hi--;
	}
	return true;
}

int main()
{
	string str = "0P";
	bool palindrome = isPalindrome(str);
	cout<<palindrome;

	return 0;
}