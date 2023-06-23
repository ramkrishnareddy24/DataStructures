#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
	 unordered_map<string,vector<string> > phonebook;

	 phonebook["rahul"].push_back("9100");
	 phonebook["rahul"].push_back("9101");
	 phonebook["rahul"].push_back("9102");
	 phonebook["rahul"].push_back("9103");

	 phonebook["kajal"].push_back("9200");
	 phonebook["kajal"].push_back("9201");
	 phonebook["kajal"].push_back("9202");
	 phonebook["kajal"].push_back("9203");

	 for(auto p:phonebook)
	 {
	 	cout<<"Name "<<p.first<<"->";
	 	for(string s:p.second){
	 		cout<<s<<",";
	 	}
	 	cout<<endl;
	 }

	 
}