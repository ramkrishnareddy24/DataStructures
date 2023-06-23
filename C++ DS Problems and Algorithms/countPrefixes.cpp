#include<bits/stdc++.h>
using namespace std;

int countPrefixes(vector<string>& words, string s) {
    int count=0;
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words[i].size() && s.size()>=words[i].size();j++)
        {
            if(words[i][j]!=s[j]) break;
            else if(j==words[i].size()-1) count++;   
        }
    }
    return count;
}

int main()
{
    vector<string> words = {"a","b","c","ab","bc","abc"}; 
    string s = "abc";
    cout<<countPrefixes(words,s)<<endl;
}