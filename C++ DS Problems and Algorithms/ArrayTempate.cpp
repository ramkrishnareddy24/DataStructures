#include<iostream>
using namespace std;

//Function Template for Array calss
template<class T>
class Array
{
private:
	T arr[100];
	int n;
public:
    void read();
    T sort();
    T delete();

};

template<class T>
void Array<T>::read()
{
	cout<<"Enter number of ele"<<endl;
	cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
}

template<class T>
T Array<T>::sort()
{
     T i,j,temp;
     int n=sizeof(arr)/sizeof(T);
     for(int i=0;i<n-1;i++)
     {
     	for(int j=i+1;j<n;j++)
     	{
     		if(arr[i]<arr[j])
     		{
     			temp=arr[i];
     			arr[i]=arr[j];
     			arr[j]=temp;
     		}
     	}
     }
}

template<class T>
T Array<T>::delete()
{
     
}