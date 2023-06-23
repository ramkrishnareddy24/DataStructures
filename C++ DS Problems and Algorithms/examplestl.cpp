#include<iostream>
#include<list>
using namespace std;

int main()
{

    list< int > myList = { 2, 6, 12, 13, 15, 18, 20};
    std::cout <<binary_search(myList.begin(), myList.end(), 20) ;

}
