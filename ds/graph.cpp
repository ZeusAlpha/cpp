#include <bits/stdc++.h>

using namespace std;

class Graph
{
	int V;
	list <int> *adj;
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void BFS(int s);
		void DFS(int v);
		void DFS_recurr(int v, bool visited[]);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for(int i=0; i<V; i++)
	{
		visited[i] = false;
	}
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	
	list<int> :: iterator i;
	while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		
		for(i = adj[s].begin(); i!= adj[s].end(); ++i)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	cout << endl;
}

void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i] = false;
	}
	DFS_recurr(v,visited);
	cout << endl;
}

void Graph::DFS_recurr(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	
	list<int>::iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); i++)
	{
		if(!visited[*i])
		{
			DFS_recurr(*i,visited);
		}
	}
}

int main()
{
	cout << "Mention the number of vertices" << endl;
	int count;
	cin >> count;
	Graph graph(count);
	cout << "Enter 9999 to end" << endl;
	int a,b;
	cin >> a;
	cin >> b;
	while(a!=9999 && b!=9999)
	{
		graph.addEdge(a,b);
		cin >> a;
		cin >> b;
	}
	cout << "Mention the starting vertex:" << endl;
	int start;
	cin >> start;
	cout << "BFS output: " << endl;
	graph.BFS(start);
	cout << "DFS output: " << endl;
	graph.DFS(start);
	return 0;
}
