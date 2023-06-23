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

void BFSdis(vector<int> adj[],int v)
{
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			BFS(adj,i,visited);
}

int main()
{
	int v=7;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	addEdge(adj,4,5);
	addEdge(adj,4,6);
	addEdge(adj,5,6);
	printEdge(adj,v);
	BFSdis(adj,v);
}

vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    int s=0;
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    visited[i]=false;
	    
	    vector<int> ans;
	    
	    queue<int> q;
	    visited[s]=true;
	    q.push(s);
	    
	    while(!q.empty())
	    {
	        int u=q.front();
	        q.pop();
	        ans.push_back(u);
	        
	        for(int v:adj[u])
	        {
	            if(visited[v]==false)
	            {
	                visited[v]=true;
	                q.push(v);
	            }
	        }
	    }
	    return ans;
	}