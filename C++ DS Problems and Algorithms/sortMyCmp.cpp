#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Point
{
	int x,y;
};

bool myCmp(Point p1,Point p2)
{
	return p1.x>p2.x;
}

int main()
{
	Point arr[]={{2,9},{3,7},{5,8}};
	int n=sizeof(arr)/sizeof(arr[0]);

	sort(arr,arr+n,myCmp);
	for(auto s:arr)
		cout<<s.x<<" "<<s.y<<endl;

	return 0;
}
