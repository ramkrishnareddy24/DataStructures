// A C++ program to print topological
// sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph {
	// No. of vertices'
	int V;

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[],
							stack<int>& Stack);

public:
	// Constructor
	Graph(int V);

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of
	// the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int s, bool visited[],stack<int>& Stack)
{
	visited[s] = true;

	for(int u:adj[s])
	{
		if(visited[u]=false)
			topologicalSortUtil(u,visited,Stack);
	}
	Stack.push(s);
}

void Graph::topologicalSort()
{
	stack<int> Stack;

	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

// Driver Code
int main()
{
	// Create a graph given in the above diagram
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,3);
	g.addEdge(3,4);
	g.addEdge(2,3);
	g.addEdge(2,4);


	cout << "Following is a Topological Sort of the given "
			"graph \n";

	// Function Call
	g.topologicalSort();

	return 0;
}
