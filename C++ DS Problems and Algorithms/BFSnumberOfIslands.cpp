// popular Interview Question to count the
// Number Of Islands using BFS
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void BFS(vector<int> adj[],int s,bool visited[])
{
	queue<int> q;
	visited[s]=true;
	q.push(s);

	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		//cout<<u<<" ";

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

int BFSdis(vector<int> adj[],int v)
{
	int count=0;
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(visited[i]==false){
			BFS(adj,i,visited);
			count++;
		}
	//cout<<endl;
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
	cout<<"Number of Islands: "<<BFSdis(adj,v);
}