#include<bits/stdc++.h>
using namespace std;

// //Efficient Solution
// void mergeWithoutExtraSpace(int arr1[],int arr2[],int m,int n)
// {
// 	int i=0,j=0;
// 	while(i<m && j<n)
// 	{
// 		if(arr1[i]<=arr2[j])
// 			cout<<arr1[i++]<<" ";
// 		else
// 			cout<<arr2[j++]<<" ";
// 	}
// 	while(i<m) cout<<arr1[i++]<<" ";
// 	while(j<n) cout<<arr2[j++]<<" ";
//  }


//Efficient Solution :Submitted
void MergeWithoutExtraSpace(int arr1[],int arr2[],int n,int m)
{
			int i=n-1;
            int j=0;
            
            while(i>=0 && j<m)
            {
                if(arr1[i]>arr2[j])
                {
                	swap(arr1[i],arr2[j]);
                	i--;
                	j++;
                }
                else
                {
                    j++;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
}

int main()
{
	int arr1[]={1,3,5,7};
	int arr2[]={0,2,6,8,9,4};
	int m=sizeof(arr1)/sizeof(arr1[0]);
	int n=sizeof(arr2)/sizeof(arr2[0]);
	// mergeWithoutExtraSpace(arr1,arr2,m,n);
	cout<<endl;
	MergeWithoutExtraSpace(arr1,arr2,m,n);
	for(int x:arr1)
		cout<<x<<" ";
	for(int y:arr2)
		cout<<y<<" ";
}