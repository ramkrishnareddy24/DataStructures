#include<bits/stdc++.h>
using namespace std;

struct Interval
{
	int start,end;
};

bool myCmp(Interval i1,Interval i2)
{
	return (i1.start<i2.start);
}

void mergeIntervals(Interval arr[],int n)
{
	sort(arr,arr+n,myCmp);

	int res=0;
	for(int i=1;i<n;i++)
	{
		if(arr[res].end>=arr[i].start)
		{
			arr[res].end=max(arr[res].end,arr[i].end);
			arr[res].start=min(arr[res].start,arr[i].start);
		}
		else
		{
			res++;
			arr[res]=arr[i];
		}
	}

	for(int i=0;i<=res;i++)
		cout<<"{"<<arr[i].start<<","<<arr[i].end<<"}"<<endl;
}

int main()
{
	Interval arr[]={{5,10},{3,15},{18,30},{2,7}};
	int n=sizeof(arr)/sizeof(arr[0]);
	mergeIntervals(arr,n);

	return 0;
}