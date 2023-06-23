#include<iostream>
using namespace std;

void TOH(int n,char A,char B,char C)
{
	if(n==1)
	{
		cout<<"Move 1 from "<<A<<" to "<<C<<endl;
		return;
	}
	TOH(n-1,A,C,B);
	cout<<"Move "<< n <<" from "<<A<<" to "<<C<<endl;
	TOH(n-1,B,A,C);
	
}

int main()
{ 
	int n=2;
	TOH(n,'A','B','C');
}

// long long toh(int N, int from, int to, int aux) {
//         // Your code here
//        static long long count=0;
//         if(N==0)
//         {
//             return 0;
//         }
    
//         toh(N-1,from,aux,to);
//         cout<<"Move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
//         count++;
//         toh(N-1,aux,to,from);
//         return count;
//     }

