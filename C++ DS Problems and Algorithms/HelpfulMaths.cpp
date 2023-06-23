#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;



int main()
{
	
	string s;
	cin>>s;
	int arr[100],k=0,n;
	
	n=s.length();

	for(int i=0;i<n;i++)
	{
		if(s[i]>=48 && s[i]<=57)
		{
			arr[k++]=s[i]-48;
		}
	}
	sort(arr,arr+k);

	for(int i=0;i<k;i++)
	{
		cout<<arr[i];
		if(i<k-1)
			cout<<"+";
	}
	return 0;
}