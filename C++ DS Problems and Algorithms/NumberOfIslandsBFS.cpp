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

void BFS(vector<int> adj[],int s,bool visited[])
{
	queue<int> q;
	visited[s]=true;
	q.push(s);

	while(!q.empty())
	{
		int u=q.front();
		// cout<<u<<" ";
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

int BFSdisconneted(vector<int> adj[],int v)
{
	int count=0;
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(visited[i]==false)
		{
			BFS(adj,i,visited);
			count++;
		}
	// cout<<endl;
	return count;
}

int main()
{
	int v=9;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,0,1);
	addEdge(adj,3,4);
	addEdge(adj,5,6);
	addEdge(adj,5,7);
	addEdge(adj,7,8);
	cout<<"The Number of Islands are: "<<BFSdisconneted(adj,v);
}