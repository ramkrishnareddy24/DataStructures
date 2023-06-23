#include<iostream>
#include<cstring>
using namespace std;

class Fun
{
public:
	void operator()(string s)
	{
		cout<<"Having sex with "<<s;
	}
};

int main()
{
	Fun f; //constructor
	f("c++");  //Overload () Operator  = Functiom call where f is an object



	return 0;
}