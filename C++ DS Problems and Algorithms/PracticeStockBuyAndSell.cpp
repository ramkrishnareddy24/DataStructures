#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int maxProfit(int price[],int start,int end)
{
	int profit=0;
	for(int i=start;i<end;i++)
	{
		for(int j=i+1;j<=end;j++)
		{
			if(price[i]<price[j])
			{
				int curr_profit=(price[j]-price[i])+maxProfit(price,start,i-1)+maxProfit(price,j+1,end);
				profit=max(profit,curr_profit);
			}
		}
	}
	return profit;
}

//Efficient Solution
int MaxProfit(int price[],int n)
{
	int profit=0;
	for(int i=1;i<n;i++)
	{
		if(price[i]>price[i-1])
		{
			profit+=price[i]-price[i-1];
		}
	}
	return profit;
}

int main()
{
	int arr[]={1,5,3,8,12};
	int n=sizeof(arr)/sizeof(arr[0]);
	int start=0;
	int end=n-1;
	cout<<maxProfit(arr,start,end);
	cout<<"\t"<<MaxProfit(arr,n);
	return 0;
}