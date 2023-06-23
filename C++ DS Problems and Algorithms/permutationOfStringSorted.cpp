#include<bits/stdc++.h>
using namespace std;

vector<string> v;
void permuteString(string a,int l,int r)
{
	if(l==r)
		v.push_back(a);
	else
    { 
       
        for (int i = l; i <= r; i++) 
        { 
  
            
            swap(a[l], a[i]); 
  
            
            permuteString(a, l+1, r); 
  
           
            swap(a[l], a[i]); 
        } 
    } 
}

void permutation(string s)
{
	int n=s.size();
	permuteString(s,0,n-1);

	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		if(i!=v.size()-1)
			cout<<v[i]<<",";
		else
			cout<<v[i];
	}

	string s1="AC";
	for(int i=0;i<v.size();i++)
		if(s1==v[i])
			cout<<"Present";
}


int main()
{
	string s="ABCD";
	// string p = "abab", s = "ab"
	permutation(s);

	return 0;
}