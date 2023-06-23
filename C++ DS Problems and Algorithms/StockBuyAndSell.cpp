#include<bits/stdc++.h>
using namespace std;

//Naive Solution
int stockBuyAndSell(int price[],int start,int end)
{
	if(end<=start)
		return 0;
	int profit=0;
	for(int i=start;i<end;i++)
	{
		for(int j=i+1;j<=end;j++)
		{
			if(price[j]>price[i])
			{
				int curr_profit = (price[j]-price[i])+stockBuyAndSell(price,start,i-1)+stockBuyAndSell(price,j+1,end);
				profit = max(profit,curr_profit);
			}
		}
	}
	return profit;
}

//Efficient Solution
int StockBuyAndSell(int arr[],int n)
{
	int profit=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
			profit+=arr[i]-arr[i-1];
	}
	return profit;
}

int main()
{
	int arr[]={100,180,260,310,40,535,695};
	int n=sizeof(arr)/sizeof(int);
	int start=0;
	int end=n-1;
	cout<<stockBuyAndSell(arr,start,end);
	cout<<"\t"<<StockBuyAndSell(arr,n);

	return 0;
}