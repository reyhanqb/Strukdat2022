#include<bits/stdc++.h>
#include <list>

using namespace std;

class Graph
{
    //jml vertex
	int V; 
	vector <list<int>> adj;
public:
	Graph(int V);

	// tambahin edge ke graph. V = Node, W = Weight
	void addEdge(int v, int w);

	// prints BFS traversal
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	vector<bool> visited;
	visited.resize(V,false);

	// Create a queue for BFS
	list<int> queue;

	// current node diflag lalu diqueue
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		// dequeue vertex -> print
		s = queue.front();
		cout << "(V" << s << ")" << endl;
		queue.pop_front();

		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

int main()
{
	Graph g(5);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(1, 3);
	g.addEdge(0, 1);

    
	cout << "Following is Breadth First Traversal " << endl;
    cout << "Starting from vertex 4 "  << endl;
	
    g.BFS(4);

	return 0;
}