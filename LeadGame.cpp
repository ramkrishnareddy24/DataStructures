#include <bits/stdc++.h>
using namespace std;

void leadGame(vector<pair<int,int>> v){
    int player=1;
    int lead=0;
    for(int i=0;i<v.size();i++){
        if(v[i].first>v[i].second){
            player=1;
            lead=v[i].first-v[i].second;
        }
    }
    cout<<player<<lead;
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int i,j;
	vector<pair<int,int>> vect;
	for(int i=0;i<n;i++){
	    cin>>i>>j;
	    vect.push_back(make_pair(i,j));
	}
	leadGame(vect);
	return 0;
}