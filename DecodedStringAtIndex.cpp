#include <bits/stdc++.h>
using namespace std;

string decodeAtIndex(string s,int k)
{
	long size = 0;
	int n = s.length();

	for(int i=0;i<n;i++){
		if(isdigit(s[i]))
			size = size*(s[i]-'0');
		else
			size++;
	}

	for(int i=n-1;i>=0;i--){
		if(isdigit(s[i])){
			size/=s[i]-'0';
			k%=size;
		}else{
			if(k==0 || k==size){
				return string(1,s[i]);
			}
			size--;
		}
	}
	return "";
}

int main()
{
	string str = "leet2code3";
	int k = 10;
	string ans = decodeAtIndex(str,k);
	cout<<ans;
	return 0;
}