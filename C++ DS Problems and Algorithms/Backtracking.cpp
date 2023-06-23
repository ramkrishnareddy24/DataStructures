#include<bits/stdc++.h>
using namespace std;

// Permutation of Strings
void permuteString(string s,int l,int r)
{
	if(l==r)
		cout<<s<<" ";
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			permuteString(s,l+1,r);
			swap(s[l],s[i]);
		}		
	}

}

// Permutation of Strings without "AB" as substr
bool isSafe(string s,int l,int i,int r)
{
	if(l!=0 && s[l-1]=='A' && s[i]=='B')
		return false;
	if(r=l+1 && s[i]=='A' && s[l]=='B')
		return false;
	return true;
}
void PermuteString(string s,int l,int r)
{
	if(l==r)
		cout<<s<<" ";
	else
	{
		for(int i=l;i<=r;i++)
		{
			if(isSafe(s,l,i,r))
			{
				swap(s[l],s[i]);
				PermuteString(s,l+1,r);
				swap(s[l],s[i]);	
			}
			
		}		
	}

}

int main()
{
	string s = "ABC";
	int n = s.size();
	permuteString(s,0,n-1);
	cout<<endl;
	PermuteString(s,0,n-1);
}