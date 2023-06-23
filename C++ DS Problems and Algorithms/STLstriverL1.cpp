#include<bits/stdc++.h>
using namespace std;

// namespace ram
// {
// 	int val=50;
// 	int getval(){
// 		return val*10;
// 	}
// }

// struct node
// {
// 	string str;
// 	int num;
// 	double doub;
// 	char x;

// 	node(str_,num_,doub_,x_)
// 	{
// 		str=str_;
// 		num=num_;
// 		doub=doub_;
// 		x=x_;
// 	}
// };

int main()
{
	// int val=50;
	double val=10.0;
	cout<<val<<endl; //prints 10
	//cout<<ram::val<<endl;  //prints 50
	//cout<<ram::getval()<<endl;

	//node ram = new node("ram",24,9.7,"");



	//Arrays in STL

	array<int, 100> arr={1,2,3};

	for(int x:arr)
		cout<<x<<" ";

	cout<<endl;

	array<int,100> arr2;
	arr.fill(5);

	for(int i=0;i<100;i++)
		cout<<arr.at(i)<<" ";

	cout<<endl;

	array<int ,5> arr3={1,2,3,4,5};

	for(auto it=arr3.begin();it!=arr3.end();it++)
		cout<<*it<<" ";

	cout<<endl;
	//prints reverse array
	for(auto it=arr3.rbegin();it!=arr3.rend();it++)
		cout<<*it<<" ";


	cout<<endl<<arr.size()<<endl;
	cout<<arr3.front()<<endl;
	cout<<arr3.back()<<endl;



	// Vector ARRAY

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.pop_back();

	v.clear();

	vector<int> vec1(4,10);

	//copy vector
	vector<int> vec2(vec1.begin(),vec1.end());
	vector<int> vec3(vec1);

	vector<int> r;
	r.push_back(1);
	r.push_back(2);
	r.push_back(3); // or emplace_back(3);

	vector<int> r1(r.begin(),r.begin()+2);




	//2D Vectors
	vector<vector<int>> vec;

	vector<int> raj;
	raj.push_back(1);
	raj.push_back(2);

	vector<int> raj2;
	raj2.push_back(10);
	raj2.push_back(20);

	vec.push_back(raj);
	vec.push_back(raj2);

	//print 2d vector0
	for(auto vctr:vec)
	{
		for(auto it:vctr)
			cout<<it<<" ";
	}cout<<endl;

	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<vec[i].size();j++)
			cout<<vec[i][j]<<" ";
	}

	vector<vector<int>> vec2(10,vector<int>(20,0)); //10x20 2d vector

	vector<int> arr[4]; //arr of vectors

	//3d Vectors 10x20x30
	vector<vector<vector<int>>> vec(10,vector<vector<int>> vec(20,vector<int>(30,0)));
}