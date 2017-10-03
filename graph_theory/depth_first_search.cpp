#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int>> &graph)
{
	for(int i=0; i<graph.size(); i++)
	{
		for(int j=0; j<graph[i].size(); j++)
		{
			cout << graph[i][j] << " "; 
		}
		cout << endl;
	}
}

void DFS(vector<vector<int>> &graph, vector<bool> &visited, int present_node)
{
	
	cout << present_node << " ";
	visited[present_node] = true;
	
	for(int i=1; i<graph[present_node].size(); i++)
	{
		if(visited[graph[present_node][i]]==false)
		{
			DFS(graph, visited, graph[present_node][i]);
		}
	}
	
}

int main()
{
	vector <vector<int>> graph;
	int V;
	cout << "Please mention the total number of vertex in the graph" << endl;
	cin >> V;
	
	for(int i=0; i<V; i++)
	{
		vector <int> temp;
		temp.push_back(i);
		graph.push_back(temp);
	}	
	
	cout << "Please mention the edges. Press 9999 to exit" << endl;
	int source;
	cin >> source;
	while(source!=9999)
	{
		int dest;
		cin >> dest;
		graph[source].push_back(dest);
		cin >> source;
	}
	//print_graph(graph);
	vector<bool> visited;
	for(int i=0; i<V; i++)
	{
		visited.push_back(false);
	}
	
	cout << "Please mention the starting node" << endl;
	int start;
	cin >> start;
	
	DFS(graph, visited, start);
	
	return 0;
}
