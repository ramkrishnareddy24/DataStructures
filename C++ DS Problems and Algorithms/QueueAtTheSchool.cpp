#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int queueAtTheSchool(char s[],int n,int t)
{
	int i,res;
	while(t!=0)
	{
		for(int i=0;i<n;i++){
			if(s[i]=='B' && s[i+1]=='G')
			{
				swap(s[i],s[i++]);
			}

		}
		t--;
	}

	return 0;

}

int main()
{
	int n,t;
	cin>>n>>t;

	char s[100];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}

	queueAtTheSchool(s,n,t);

	for(int i=0;i<n;i++)
	{
		cout<<s[i];
	}
}