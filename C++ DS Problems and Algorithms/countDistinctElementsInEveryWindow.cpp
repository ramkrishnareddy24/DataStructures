#include<iostream>
#include<unordered_map>
using namespace std;

//Naive Solution
int printDistinctCount(int arr[],int n,int k)
{
	for(int i=0;i<=n-k;i++)
	{
		int count=0;
		for(int j=0;j<k;j++)
		{
			bool flag=false;
			for(int p=0;p<j;p++)
				if(arr[i+j]==arr[i+p])
				{
					flag=true;
					break;
				}
				if(flag==false)
					count++;
		}
		cout<<count<<" ";
	}
}

//Efficient Solution
void printDistinct(int arr[],int n,int k)
{
    unordered_map<int,int> m;
    
    for (int i=0;i<k;i++)
    {
        m[arr[i]]++;
    } 
    cout<<m.size()<<" "; 
    
    for(int i=k;i<n;i++)
    { 
        m[arr[i-k]]--;
        
        if(m[arr[i-k]]==0)
        { 
            m.erase(arr[i-k]); 
        }   
        m[arr[i]]++;
    
        cout<<m.size()<<" ";
    }
}

int main()
{
	int arr[]={10,10,5,3,10,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<printDistinctCount(arr,n,4)<<endl;
	printDistinct(arr,n,4);
	return 0;
}