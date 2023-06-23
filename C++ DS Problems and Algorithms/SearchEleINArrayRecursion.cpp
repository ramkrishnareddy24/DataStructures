#include<iostream>
using namespace std;

int SearchRec(int arr[],int n,int x)
{
	if(n>=0)
	{
		if(arr[n-1]==x)
			return n;
		else
			return SearchRec(arr,n-1,x);
		n--;
	}

}

int main()
{
	int arr[100];
	int i,n,pos=0;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int x;
	cin>>x;

	pos=SearchRec(arr,n,x);

	if(pos!=0)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;

	}

}