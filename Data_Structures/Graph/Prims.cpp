#include <iostream>
#include <bits/stdc++.h>
#define V 5
#define INF 999999
using namespace std;

int minDistance(int distances[], bool visited[])
{
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++)
    {
        if (distances[i] < min && visited[i] == false)
        {
            min = distances[i];
            min_index = i;
        }
    }
    return min_index;
}

void prims(int graph[][V])
{
    bool visited[V];
    int distances[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        distances[i] = INF;
    }
    distances[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < V - 1; ++i) //Vertices
    {
        int u = minDistance(distances, visited);
        visited[u] = true;
        cout << "u: " << u << endl;
        for (int j = 0; j < V; ++j)
        {

            if (graph[u][j] && graph[u][j] != INF && visited[j] == false && graph[u][j] < distances[j])
            {
                cout << " j: " << j << endl;
                distances[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " to " << i << " cost is " << distances[i] << endl;
    }
}
int main()
{
    int graph[V][V] = {{0, 8, INF, INF, 5},
                       {8, 0, INF, 10, 3},
                       {INF, INF, 0, 8, 6},
                       {INF, 10, 8, 0, 2},
                       {5, 3, 6, 2, 0}};
    prims(graph);
}