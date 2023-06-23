#include<iostream>
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

void BFS(vector<int> adj[],int v,int s)
{
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[i]=false;

	queue<int> q;
	visited[s]=true;
	q.push(s);

	while(!q.empty())
	{
		int u=q.front();
		cout<<u<<" ";
		q.pop();

		for(int v:adj[u])
		{
			if(visited[v]==false)
			{
				visited[v]=true;
				q.push(v);
			}
		}
	}
}

int main()
{
	int v=4;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	printEdge(adj,v);
	BFS(adj,v,0);

	return 0;
}