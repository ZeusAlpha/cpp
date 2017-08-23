#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertex_count;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int s);
};

void Graph::BFS(int s)
{
    bool *visited = new bool[vertex_count];
    for(int i=0;i<vertex_count;i++)
    {
        visited[i] = false;
    }

    list <int> queue;
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(i=adj[s].begin();i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

Graph :: Graph(int v)
{
    this->vertex_count = v;
    adj = new list<int>[vertex_count];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,1);
    g.BFS(2);
    return 255;
}