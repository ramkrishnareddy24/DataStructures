#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void DFSRec(vector<int> adj[],int s,bool visited[])
{
	visited[s]=true;
	cout<<s<<" ";

	for(int u:adj[s])
	{
		if(visited[u]==false)
			DFSRec(adj,u,visited);
	}
}

void DFS(vector<int> adj[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			DFSRec(adj,i,visited);
}

int main()
{
	int v=9;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	addEdge(adj,4,5);
	addEdge(adj,4,6);
	addEdge(adj,5,6);
	DFS(adj,v);

	return 0;
}