#include<bits/stdc++.h>
using namespace std;

string convert(string str,int numRows)
{
	if(numRows==1) return str;
	vector<string> ans(numRows);
	bool flag = false;
	int i=0;

	for(auto ch:str)
	{
		ans[i]+=ch;
		if(i==0 || i==numRows-1)
			flag = !flag;
		if(flag)
			i+=1;
		else
			i-=1;
	}
	string zigzag = "";
	for(auto s:ans)
		zigzag+=s;
	return zigzag;
}

int main()
{
	string str = "PAYPALISHIRING";
	int numRows = 3;
	string zigzag = convert(str,numRows);
	cout<<zigzag;

	return 0;
}