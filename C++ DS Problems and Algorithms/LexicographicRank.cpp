#include<iostream>
#include<cstring>
using namespace std;

int fact(int n,int k=1)
{
	if(n==0)
		return k;
	return fact(n-1,n*k);  //Tail-Recursive call

}

int LexicographicRank(string s)
{
	int rank=1;
	int n=s.length();
	int mul=fact(n);
	int count[256]={0};

	for(int i=0;i<n;i++)
	{
		count[s[i]]++;
	}
	for(int i=1;i<256;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for(int i=0;i<n;i++)
	{
		mul=mul/(n-i);
		rank=rank+count[s[i]-1]*mul;
		for(int j=s[i];j<256;j++)
			count[j]--;
	}
	return rank;
}



int main()
{
	string s="STRING";

	cout<<LexicographicRank(s);
}


// #define mod 1000000007;
//     long long fact(long long n)
//    {
//     long long res=1;
//     for(long long i=1;i<=n;i++)
//     {
//         res=res*1ll *i%mod;
//     }
//     return res;
//     }
//     int findRank(string s) 
//     {
  
//       forlong long rep[256]={0};
//     for(long long i=0;i<s.length();i++)
//     {
//         rep[s[i]]++;
//     }
//     for(long long i=0;i<256;i++)
//     {
//        // cout<<rep[i]<<" ";
//         if(rep[i]>1)
//             return 0;
//     }
//     long long n=s.length();
//     long long hash[256]={0};
//     for(long long i=0;i<n;i++)
//     {
//         hash[s[i]]++;
//     }
//     for(long long i=1;i<256;i++)
//     {
//         hash[i]+=hash[i-1];
//     }
//     long long res=1;
//     for(long long i=0;i<n-1;i++)
//     {
//         //mul=mul/(n-i);
//         res+=(hash[s[i]-1]*fact(n-i-1))%mod;
//         for(long long j=s[i];j<256;j++)
//             hash[j]--;
//     }
//     return (res)%mod;
//     }