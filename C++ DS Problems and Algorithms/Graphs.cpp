#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void AddEdgeWeight(vector<pair<int,int>> adj[],int u,int v,int wt)
{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}

void printGraph(vector<int> adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		for(auto x:adj[i])
			cout<<x<<" ";
		cout<<"\n";
	}
}

// Breadth First Traversal of Connected Graph
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


// Breadth First Search of Disconnected Graph
void bfs(vector<int> adj[],int s,bool visited[])
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
			bfs(adj,i,visited);
}

// Number of Islands in Undirected Graph
void bFs(vector<int> adj[],int s,bool visited[])
{
	queue<int> q;
	visited[s]=true;
	q.push(s);

	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		// cout<<u<<" ";

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
			bFs(adj,i,visited);
			count++;
		}
		
	}
	return count;
}

// Depth First Search
void DFSrec(vector<int> adj[],int s,bool visited[])
{
	visited[s]=true;
	cout<<s<<" ";

	for(int v:adj[s])
	{
		if(visited[v]==false)
		{
			DFSrec(adj,v,visited);
		}
	}
	
}
void DFS(vector<int> adj[],int v,int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	DFSrec(adj,s,visited);
}

// DFS for Disconnected Graph
void dfsDis(vector<int> adj[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			DFSrec(adj,i,visited);
}

// Detect cycle in Undirected Graph
int DFSRec(vector<int> adj[],int s,bool visited[],int parent)
{
	visited[s]=true;

	for(int u:adj[s])
	{
		if(visited[u]==false)
		{
			if(DFSRec(adj,u,visited,s)==true)
				return true;
		}
		else if(u!=parent)
		{
			return true;
		}
	}
	return false;
}

int DFS(vector<int> adj[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			if(DFSRec(adj,i,visited,-1)==true)
				return true;
	}
	return false;
}

// Detect Cycle in Directed Graph
int dfsRecDirected(vector<int> adj[],int s,bool visited[],bool recSt[])
{
	visited[s]=true;
	recSt[s]=true;

	for(int u:adj[s])
	{
		if(visited[u]==false && dfsRecDirected(adj,u,visited,recSt))
			return true;
		else if(recSt[u]==true)
			return true;
	}
	recSt[s]=false;
	return false;
}

int dfsRec(vector<int> adj[],int v)
{
	bool visited[v];
	bool recSt[v];

	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		recSt[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			if(dfsRecDirected(adj,i,visited,recSt)==true)
				return true;
	}
	return false;
}

// Topological Sort DFS
void topologicalSortUtil(vector<int> adj[],int s,bool visited[],stack<int>& st)
{
	visited[s]=true;

	for(int u:adj[s])
	{
		if(visited[u]==false)
			topologicalSortUtil(adj,u,visited,st);
	}
	st.push(s);
}

void topologicalSort(vector<int> adj[],int v)
{
	bool visited[v];
	stack<int> st;

	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			topologicalSortUtil(adj,i,visited,st);
	}

	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}

}

// Shortest Path in DAG
void findTopoSort(int s,int visited[],stack<int>& st,vector<pair<int,int>> adj[])
{
	visited[s]=true;

	for(auto it:adj[s])
	{
		if(!visited[it.first])
			findTopoSort(it.first,visited,st,adj);
	}
	st.push(s);
}

void shortestPath(int s,int v,vector<pair<int,int>> adj[])
{
	int visited[v]={0};
	stack<int> st;

	for(int i=0;i<v;i++)
		if(!visited[i])
			findTopoSort(i,visited,st,adj);


	int dist[v];
	for(int i=0;i<v;i++)
		dist[i]=INT_MAX;
	dist[s]=0;

	while(!st.empty())
	{
		int node=st.top();
		st.pop();

		if(dist[node]!=INT_MAX)
		{
			for(auto it:adj[node]){
				if(dist[node]+it.second<dist[it.first]){
					dist[it.first]=dist[node]+it.second;
				}
			}
		}
	}

	for(int i=0;i<v;i++)
		if(dist[i]==INT_MAX)
			cout<<"INF";
		else
			cout<<dist[i]<<" ";
}

// Prim's MST Algorithm
// int primsMST(vector<int> graph[],int v)
// {
// 	int key[v];
// 	for(int i=0;i<v;i++)
// 		key[i]=INT_MAX;
// 	key[0]=0;
// 	bool mSet[v];
// 	for(int i=0;i<v;v++)
// 		mSet[i]=false;

// 	for(int count=0;count<v;count++)
// 	{
// 		int u=-1;
// 		for(int i=0;i<v;i++)
// 			if(!mSet[i] && (u==-1 || key[i]<key[u]))
// 				u=i;

// 		mSet=true;
// 		res=res+key[u];
// 		for(int V=0;V<v;V++)
// 		{
// 			if(graph[u][V]!=0 && !mSet[V])
// 				key[V]=min(key[V],graph[u][V]);
// 		}
// 	}
// 	return res;
// }

// Dijkstra's Algorithm
vector<int> dijkstras(vector<int> graph[],int s,int V)
{
	vector<int> dist(V,INT_MAX);
	dist[s]=0;
	vector<bool> fin(V,false);

	for(int count=0;count<V-1;count++)
	{
		int u=-1;
		for(int i=0;i<V;i++)
		{
			if(!fin[i] && (u==-1 || dist[i]<dist[u]))
				u=i;
			fin[i]=true;
		}

		for(int v=0;v<V;v++)
		{
			if(!fin[v] && graph[u][v]!=0)
				dist[v]=min(dist[v],dist[u]+graph[u][v]);
		}
	}
	return dist;
}

// Dijkstra's Shortest Path Algorithm
void DijkstrasShortestPath(vector<pair<int,int>> graph[],int s,int v)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<int> distTo(v+1,INT_MAX);

	distTo[s]=0;
	pq.push(make_pair(0,s));

	while(!pq.empty())
	{
		int dist = pq.top().first;
		int prev = pq.top().second;

		for(auto it:graph[prev])
		{
			int u = it.first;
			int v = it.second;
			if(distTo[u] > dist+v)
			{
				distTo[u] = distTo[prev]+v;
				pq.push(make_pair(distTo[u],u));
			}
		}
	}

	for(int i=0;i<=v;i++)
		cout<<distTo[i]<<" ";
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
	// printGraph(adj,V);
	// cout<<endl;
	BFS(adj,V,0);
	cout<<endl;
	bfsDisconnected(adj,V);
	cout<<endl;
	cout<<"number of islands :"<<numberOfIslands(adj,V);
	cout<<endl;

	int v=6;
	vector<int> adj1[v];
	addEdge(adj1,0,1);
	addEdge(adj1,1,2);
	addEdge(adj1,1,3);
	addEdge(adj1,2,3);
	addEdge(adj1,2,4);
	addEdge(adj1,4,5);
	// addEdge(adj1,5,6);
	// addEdge(adj1,5,7);
	// addEdge(adj1,6,7);
	// DFS(adj1,v,0);
	// cout<<endl;
	// dfsDis(adj1,v); 
	cout<<"is Cycle Present? :"<<DFS(adj1,v)<<endl;

	int z=6;
	vector<int> adj2[z];
	addEdge(adj2,0,1);
	addEdge(adj2,2,1);
	addEdge(adj2,2,3);
	addEdge(adj2,3,4);
	addEdge(adj2,4,5);
	addEdge(adj2,5,3);
	cout<<"is Cycle present (Directed): "<<dfsRec(adj2,z);

	int z1=4;
	vector<int> adj3[z1];
	addEdge(adj3,0,1);
	addEdge(adj3,1,2);
	// addEdge(adj3,3,4);
	addEdge(adj3,2,3);
	addEdge(adj3,1,3);
	cout<<endl<<"topologicalSort: ";
	topologicalSort(adj3,z1);

	int n=6;
	vector<pair<int,int>> adj4[n];
	// adj4[u].push_back({v,wt});
	adj4[0].push_back({1,1});
	adj4[1].push_back({2,3});
	adj4[2].push_back({3,4});
	adj4[1].push_back({3,2});
	// cout<<endl<<"Shortest Path: ";
	// shortestPath(0,n,adj4);

	int n1=3;
	vector<pair<int,int>> adj5[n1];
	AddEdgeWeight(adj5,0,1,5);
	AddEdgeWeight(adj5,0,2,3);
	AddEdgeWeight(adj5,1,2,1);
	// AddEdgeWeight(adj5,1,3,40);
	// AddEdgeWeight(adj5,1,4,50);
	// AddEdgeWeight(adj5,2,3,60);
	// AddEdgeWeight(adj5,3,4,70);
	DijkstrasShortestPath(adj5,1,n1);
	return 0;
}