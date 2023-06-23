#include<bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    int low=0,high=s.length()-1;
    while(low<=high)
    {
        swap(s[low],s[high]);
        low++;
        high--;
    }
    return s;
}

string thousandSeparator(int n)
{
    if(n==0) return "0";
    if(n<=999){
        string a = to_string(n);
        return a;
    };

    string ans;
    
    string s = to_string(n);
    string x = reverse(s);
    int added = 0;

    for(int i=0;i<s.length();i++)
    {
        if(added==3)
        {
            ans.push_back('.');
            added=0;
        }
        ans.push_back(x[i]);
        added++;
    }

    return reverse(ans);
}

int main()
{
    int num = 2012365487;
    cout<<thousandSeparator(num);
}