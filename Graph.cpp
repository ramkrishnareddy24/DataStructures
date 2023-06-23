#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		for(auto x:adj[i])
			cout<<x<<" ";
		cout<<endl;
	}
}

// bfs connected
void bfs(vector<int> adj[],int v,int s)
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
		q.pop();
		cout<<u<<" ";

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

// bfs disconnected
void Bfs(vector<int> adj[],int s,bool visited[])
{
	queue<int> q;
	visited[s]=true;
	q.push(s);

	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		cout<<u<<" ";

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

void bfsDisconnected(vector<int> adj[],int v)
{
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			Bfs(adj,i,visited);
}

// Number of Islands
void BFS(vector<int> adj[],int s,bool visited[])
{
	queue<int> q;
	visited[s]=true;
	q.push(s);

	while(!q.empty())
	{
		int u=q.front();
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
int numberOfIslands(vector<int> adj[],int v)
{
	int count=0;
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			BFS(adj,i,visited);
			count++;	
		}
	}
	return count;
}

// DFS
void dfsRec(vector<int> adj[],int s,bool visited[])
{
	visited[s]=true;
	cout<<s<<" ";

	for(int v:adj[s])
	{
		if(visited[v]==false)
			dfsRec(adj,v,visited);
	}
}
void dfs(vector<int> adj[],int v,int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	dfsRec(adj,s,visited);
}

// dfs disconnected
void dfsDisconnect(vector<int> adj[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			dfsRec(adj,i,visited);
}

// detect Cycle in Undirected Graph
int dfsDetect(vector<int> adj[],int s,bool visited[],int parent)
{
	visited[s]=true;

	for(int u:adj[s])
	{
		if(visited[u]==false)
		{
			if(dfsDetect(adj,u,visited,s))
				return true;
		}
		else if(u!=parent)
		{
			return false;
		}
	}
}
int detectCycle(vector<int> adj[],int v)
{
	bool visited[v]=true;
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			if(dfsDetect(adj,i,visited,-1))
				return true;
	return false;
}



int main()
{
	int V=8;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,2,3);
	addEdge(adj,2,4);
	addEdge(adj,3,4);
	addEdge(adj,5,6);
	addEdge(adj,5,7);
	// cout<<"printGraph :"<<endl;printGraph(adj,v);
	// cout<<"bfs :"<<endl;bfs(adj,v,0);
	// cout<<endl<<"printGraph :"<<endl;printGraph(adj,v);
	// cout<<"bfsDisconnected :"<<endl; bfsDisconnected(adj,V);
	// cout<<"Number of Islands :"<<numberOfIslands(adj,V)<<endl;
	cout<<"dfs :"<<endl;dfs(adj,V,4);
	cout<<"dfsDisconnect :"<<endl;dfsDisconnect(adj,V);

	return 0;
}