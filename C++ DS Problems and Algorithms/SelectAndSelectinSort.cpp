#include<iostream>
#include<bits/stdc++.h>
using namespace std;


    int select(int arr[], int i)
    {
        // code here such that selectionSort() sorts arr[]
        for(int j=i;j>=0;j--){
            if(arr[j]>arr[i])
                i=j;
        }
        return i;
        
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       for(int i=n-1;i>=0;i--){
           swap(arr[i],arr[select(arr,i)]);
       }
    }


int main()
{
    int arr[]={4,3,15,9};
    int n=sizeof(arr)/sizeof(int);

    selectionSort(arr,n);

    for(auto x:arr)
    {
        cout<<x<<" ";
    }
}