#include<bits/stdc++.h>
using namespace std;
#define V 5
void bellman(int graph[][V], int source)
{
    int distance[V];
    bool Visited[V];
    for(int i=0;i<V;i++)
        {distance[i]=INT_MAX;
        Visited[i] = false;}
    distance[source]=0;
}
int main()
{
    int graph[V][V]={{0,2,0,0,5},
                    {2,0,1,2,10},
                    {0,1,0,6,3},
                    {0,2,6,0,4},
                    {5,10,3,4,0}};
    bellman(graph,2);
}