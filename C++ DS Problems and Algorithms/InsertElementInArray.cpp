#include<iostream>
using namespace std;

int Insert(int arr[],int n,int x,int cap,int pos)
{
	if(n==cap)
		return n;
	int idx=pos-1;
	for(int i=n-1;i>=idx;i--)
		arr[i+1]=arr[i];
	arr[idx]=x;
	return (n+1);
}

int main()
{
	/*int arr[10];
	int cap=10;
	int i,pos,n,x;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	} cout<<endl;

	cout<<"Enter an element to Insert: ";
	cin>>x;
	cout<<"Enter the Position: ";
	cin>>pos;

	cout<<Insert(arr,n,x,cap,pos)<<endl;

	cout<<"After Insertion"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}*/
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	int i,pos,x,cap;
	cout<<"Enter cap: "; cin>>cap;
	cout<<"Enter pos: "; cin>>pos;
	cout<<"Enter ele to be Inserted: "; cin>>x;

	cout<<Insert(arr,n,x,cap,pos)<<endl;

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}	

}