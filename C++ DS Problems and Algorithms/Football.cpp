#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int count1=1;

	for(size_t i=1;i<s.length();++i)
	{
		if(s[i]==s[i-1]){
			count1+=1;
		
			if(count1==7){
				cout<<"YES"<<endl;
				return 0;
			}
			
	    }
		else{
			count1=1;
		}
		
	
		
	}
	cout<<"NO"<<endl;
	
	return 0;
}