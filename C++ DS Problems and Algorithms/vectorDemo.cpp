// C++ program to demonstrate map
#include<iostream>
#include<map>
using namespace std;

int main(){
    string name;
    int wkt;

    map<string,int> wicket;

    cout<<"Enter 3 sets of cricketer-name and no. of wickets"<<endl;

    for(int i=0;i<3;i++){
        cin>>name;
        cin>>wkt;
        //wicket[name] = wkt; //map-name[key] = value;
        wicket.insert(pair<string,int> (name,wkt));
    }

    cout<<"Contents of wicket map -- before adding KD"<<endl;
    for(map<string,int>::iterator itr=wicket.begin();itr!=wicket.end();itr++){
        cout<<itr->first<<" : "<<itr->second<<endl;
    }

    wicket["KapilDev"] = 253;

    cout<<"Contents of wicket map -- after adding KD"<<endl;
    for(map<string,int>::iterator itr=wicket.begin();itr!=wicket.end();itr++){
        //cout<<itr->first<<" : "<<itr->second<<endl;
        cout<<(*itr).first<<" : "<<(*itr).second<<endl;
    }
}
