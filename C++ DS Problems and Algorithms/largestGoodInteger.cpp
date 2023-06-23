#include<bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num)
{
    char ans = 0;
    for(int i=2;i<num.size();i++)
    {
        if(num[i-2]==num[i-1] && num[i-1]==num[i])
            ans = max(ans,num[i]);
    }
    if(ans==0) return "";
    return string(3,ans);
}

int main()
{
    string num = "6777133339";
    cout<<largestGoodInteger(num);
}