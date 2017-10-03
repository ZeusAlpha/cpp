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

void BFS(vector<vector<int>> &graph,int V)
{
	cout << "Please mention the starting node" << endl;
	int start;
	cin >> start;
	
	bool visited[V];
	for(int i=0; i<V; i++)
	{
		visited[i] =false;
	}
	
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while(!q.empty())
	{
		int s = q.front();
		cout << s << " ";
		q.pop();
		
		for(int i=1; i<graph[s].size(); i++)
		{
			if(visited[graph[s][i]]==false)
			{
				visited[graph[s][i]] = true;
				q.push(graph[s][i]);
				//cout << visited[graph[s][i]] << "  fgfdsf" << endl;
			}
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
	print_graph(graph);
	BFS(graph, V);
	
	return 0;
}
