#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> mp;

void SymbolTable()
{
	mp.insert({"COPY","0000"});
	mp.insert({"FIRST","0001"});
	mp.insert({"CLOOP","0006"});
	mp.insert({"ENDFILL","001A"});
	mp.insert({"EOF","002D"});
	mp.insert({"RETADR","0030"});
	mp.insert({"LENGTH","0033"});
	mp.insert({"BUFFER","0036"});
	mp.insert({"WRREC","2061"});
	mp.insert({"WLOOP","2064"});
	mp.insert({"OUTPUT","2079"});
	mp.insert({"RDREC","2039"});
	mp.insert({"RLOOP","203F"});
	mp.insert({"EXIT","2057"});
	mp.insert({"INPUT","205D"});
	mp.insert({"MAXLEN","205E"});
	mp.insert({"THREE","102D"});
	mp.insert({"ENDFILL","1015"});
	mp.insert({"BRA","55H"});
	mp.insert({"CMP","21H"});
	mp.insert({"MOV","88H"});
	mp.insert({"POP","32H"});
	mp.insert({"RET","01H"});
	mp.insert({"SHR","42H"});
}

void insert(string value,string symbol)
{
	mp.insert({value,symbol});
}

void search(string value)
{
	auto it=mp.find(value);
	if(it!=mp.end())
		cout<<(it->first)<<" "<<(it->second)<<endl;
	else
		cout<<"Not Found"<<endl;

}

void deleteVal(string value)
{
	auto it=mp.find(value);
	if(it!=mp.end())
	{
		cout<<"Removed "<<it->first<<" "<<it->second<<endl;
		mp.erase(it);
	}
	else if(it==mp.end())
	{
		cout<<"Key NOT found to delete";
	}
}

void print()
{
	for(auto it=mp.begin();it!=mp.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
}

int main()
{
	int choice;
	string value;
	string symbol;
	SymbolTable();
	cout<<"1. Insert"<<endl<<"2. PrintMap"<<endl<<"3. Search"<<endl<<"4. Delete"<<endl<<"5. Exit"<<endl;
	while(1)
	{
		cout<<"Enter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: cout<<"Enter value and symbol"<<endl;
					cin>>value>>symbol;
					insert(value,symbol);
					break;
			case 2: print();
					break;
			case 3: cout<<"Enter value to search: "; cin>>value;
					search(value);
					break;
			case 4: cout<<"Enter value to be deleted: "; cin>>value;
					deleteVal(value);
					break;
			case 5: exit(0);
			default : cout<<"Enter Correct choice"<<endl;
		}
	}
}