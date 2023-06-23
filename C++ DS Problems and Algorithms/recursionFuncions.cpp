#include<bits/stdc++.h>
using namespace std;

void fun(int n)
{
	if(n<1)
		return;
	else
	{
		cout<<n<<" ";
		fun(n-1);
		cout<<n<<" ";
	}
}

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}

int fibonacci(int n)
{
	if(n==0)
		return 0;
	else
		if(n==1)
			return 1;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

void print1ToN(int n)
{
	if(n<1)
		return;
	else
		print1ToN(n-1);
		cout<<n<<" ";	//it prints 1 to N		
}

//Modified Tail Recursive of above function
void print1ToN_tailRec(int n,int k)
{
	if(n<1)
		return;
	else
		cout<<k<<" ";
	print1ToN_tailRec(n-1,k+1);
}

//Tail Recursive
void printNTo1(int n)
{
	if(n<1)
		return;
	else
		cout<<n<<" ";	//prints N to 1
		printNTo1(n-1);
}

//tail Recursive of factorial
int fact_tail(int n,int k=1)
{
	if(n==0)
		return k;
	else
		return fact_tail(n-1,n*k);
}

bool isPalindrome(string str,int s,int e)
{
	if(s==e) return true;
	if(s>e) return true;
	if(str[s]!=str[e])
		return false;
	return isPalindrome(str,s+1,e-1);
}

int sumOfDigits(int n)
{
	if(n<10)
		return n;
	return (n%10)+sumOfDigits(n/10);
}

// Rope Cut Problem
// int maxCuts(int n,int a,int b,int c)
// {
// 	if(n==0) return 0;
// 	if(n<0) return -1;

// 	int res=max(maxCuts(n-a,a,b,c),maxCuts(n-b,a,b,c),maxCuts(n-c,a,b,c));

// 	if(res==-1)
// 		return -1;
// 	return (res+1);
// }

//All Possible subsets of a STRING
void printSub(string str,string curr="",int index=0)
{
	if(index==str.length())
	{
		cout<<curr<<"- -";
		return;
	}
	printSub(str,curr,index+1);
	printSub(str,curr+str[index],index+1);
}

//Tower Of Hanoi problem
void TOH(int n,char A,char B,char C)
{
	if(n==1)
	{
		cout<<"Move disk 1 from "<<A<<" to "<<C<<endl;
		return;
	}
	TOH(n-1,A,C,B);
	cout<<"Move disk "<<n<<" from "<<A<<" to "<<C<<endl;
	TOH(n-1,B,A,C);
}

int main()
{
	fun(3);
	cout<<endl<<fact(0)<<endl;
	cout<<fibonacci(4)<<endl;
	print1ToN(5);
	cout<<endl;
	printNTo1(5);
	cout<<endl;
	print1ToN_tailRec(5,1);
	cout<<endl;
	cout<<fact_tail(4);
	cout<<endl;
	string str="abba";
	int s=0;
	int e=str.length()-1;
	cout<<isPalindrome(str,s,e);
	cout<<endl<<sumOfDigits(9999)<<endl;
	//cout<<maxCuts(23,12,9,11);
	printSub("ABC");
	cout<<endl;
	TOH(3,'A','B','C');
}