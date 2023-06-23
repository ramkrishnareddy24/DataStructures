#include<bits/stdc++.h>
using namespace std;

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

//Efficient Solution
bool palindromeWithSpaces(string str)
{
	string tempstr="";
	transform(str.begin(),str.end(),str.begin(),::toupper);

	for(int i=0;i<str.length();i++)
	{
		if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9'))
			tempstr+=str[i];
	}
	str=tempstr;
	cout<<str<<endl;

	int low=0;
	int high=str.length()-1;
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
	string single_word="malayalam";
	string multiple_words="Was it a car or a cat i saw";
	cout<<palindrome(single_word)<<endl;
	cout<<palindromeWithSpaces(multiple_words);
	return 0;
}