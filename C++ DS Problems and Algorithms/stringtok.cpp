/*#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a,string b)
{
	if(a.length()==b.length())
	{
		return a<b;
	}
	return a.length()>b.length();
}  
int main()
{
	int n;
	cin>>n;
	cin.get();

	string s[100];
    
	for(int i=0;i<n;i++)
	{
		getline(cin,s[i]);
	}

	sort(s,s+n,compare);

	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}

}*/

#include<iostream>
#include<cstring>
using namespace std;

void f(){

	     char s1[] = "CobingBlocks";
         char s2 = 'B';
         char *ptr = strchr( s1, s2);
         cout << ptr;
	}

	int main()
	{
		f();
	}