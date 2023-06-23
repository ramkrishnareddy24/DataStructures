#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printEdge(vector<int> adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		for(int x:adj[i])
			cout<<x<<" ";
		cout<<endl;
	}
}

// void printEdge(vector<int> adj[],int v)
// {
// 	vector<vector<int>> vec(v);
// 	for(int i=0;i<v;i++)
// 	{
// 		vec[i].push_back(v);
// 		vec[i].push_back(vec[i].end(),adj[i].begin(),adj[i].end());
// 	}
// }

int main()
{
	int v=4;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	printEdge(adj,v);

	return 0;
}

