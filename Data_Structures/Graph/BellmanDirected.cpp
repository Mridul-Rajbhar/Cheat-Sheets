
#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int src;
    int dest;
    int weight;
};
class graph
{
public:
    int V;
    int E;
    edge *edges;
};

graph *CreateGraph(int edges, int vertices)
{
    graph *g = new graph;
    g->E = edges;
    g->V = vertices;
    g->edges = new edge[edges];
    return g;
}
void bellman(graph *g, int source)
{
    bool answer = true;
    int V = g->V;
    vector<int> distance(1);
    distance[V];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    distance[source] = 0;
    for (int i = 0; i < V - 1; ++i)
    {
        for (int j = 0; j < g->E; ++j)
        {
            int u = g->edges[j].src;
            int v = g->edges[j].dest;
            int wht = g->edges[j].weight;
            if (distance[j] != INT_MAX && distance[u] + wht < distance[v])
                distance[v] = distance[u] + wht;
        }
    }
    for (int j = 0; j < g->E; ++j)
    {
        int u = g->edges[j].src;
        int v = g->edges[j].dest;
        int wht = g->edges[j].weight;
        if (distance[j] != INT_MAX && distance[u] + wht < distance[v])
        {
            answer = false;
            break;
        }
    }
    if (answer)
    {
        cout << "Distance of source " << source << " from " << endl;
        for (int i = 0; i < g->V; ++i)
        {
            cout << i << " is " << distance[i] << endl;
        }
    }
    else
    {
        cout << "Negative cycle";
    }
}
int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices" << endl;
    cin >> vertices;
    cout << "Enter the number of edges" << endl;
    cin >> edges;
    graph *g = CreateGraph(edges, vertices);
    int source, destination, weight;

    for (int i = 0; i < edges; i++)
    {
        cout << "source destination and weight" << endl;
        cin >> source >> destination >> weight;
        g->edges[i].src = source;
        g->edges[i].dest = destination;
        g->edges[i].weight = weight;
    }
    bellman(g, 0);
    return 0;
}