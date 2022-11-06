#include <bits/stdc++.h>
#define V 4
#define INF 99999999
using namespace std;

void Floyd(int graph[][V])
{
    int distance[V][V];
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            distance[i][j] = graph[i][j];
        }
    }
    for (int intermidiates = 0; intermidiates < V; ++intermidiates)
    {
        for (int source = 0; source < V; ++source)
        {
            for (int vertex = 0; vertex < V; ++vertex)
            {
                if ((distance[source][intermidiates] + distance[intermidiates][vertex]) < distance[source][vertex])
                {
                    distance[source][vertex] = distance[source][intermidiates] + distance[intermidiates][vertex];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    Floyd(graph);
}