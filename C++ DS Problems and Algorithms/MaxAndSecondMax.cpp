#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
        int max=0,max2=-1;
        vector<int> v;
        for(int i=1;i<sizeOfArray;i++)
        {
        	if(arr[i]>arr[max])
        	{
        		max2=max;
        		max=i;
        	}
        	else
        	if(arr[i]!=arr[max]){
        		if(max2==-1 || arr[i]>arr[max2])
       			max2=i;
       		}
        }
        v.push_back(arr[max]);
        v.push_back(arr[max2]);
       return v;
    }
};

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
		int sizeOfArray;
		cin>>sizeOfArray;

		int arr[sizeOfArray];

		for(int index=0;index<sizeOfArray;index++)
		{
			cin>>arr[index];
		}
		Solution obj;
		vector<int> ans = obj.largestAndSecondLargest(sizeOfArray,arr);
		cout<<ans[0]<<' '<<ans[1]<<endl;
	}
}