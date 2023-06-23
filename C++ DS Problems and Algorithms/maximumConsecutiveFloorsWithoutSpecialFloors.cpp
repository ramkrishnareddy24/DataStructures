#include<bits/stdc++.h>
using namespace std;

int maxConsecutive(int bottom, int top, vector<int>& special) {
    
    int n = special.size();
    sort(special.begin(),special.end());

    int res = max(special[0]-bottom,top-special[n-1]);
    for(int i=1;i<n;i++)
        res = max(res,special[i]-special[i-1]-1);
    return res;
}

int main()
{
    int bottom = 2, top = 9;
    vector<int> special = {4,6};
    cout<<maxConsecutive(bottom,top,special);
}