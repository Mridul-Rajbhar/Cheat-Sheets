#include<bits/stdc++.h>
using namespace std;
#define V 5

int minDistance(int MinimumPath[], bool Visited[])
{
    int min=INT_MAX, min_index;
    for(int v=0; v<V;v++)
    {
        if(Visited[v]==false && MinimumPath[v]<=min)
        {
            min = MinimumPath[v];
            min_index=v;
        }
    }
    return min_index;
}

void dijktras(int graph[][V],int src)
{
    int MinimumPath[V];
    bool Visited[V];
    for(int i=0;i<V;++i)
    {
        MinimumPath[i]=INT_MAX;
        Visited[i]=false;
    }
    MinimumPath[src]=0;

    for(int count=0;count<V-1;++count)
    {
        int u=minDistance(MinimumPath,Visited);

        Visited[u]=true;
        for(int v=0;v<V;++v)
        {
            if(!Visited[v] && graph[u][v] && MinimumPath[u]!=INT_MAX && (MinimumPath[u]+graph[u][v])<MinimumPath[v])
                {
                    MinimumPath[v]=MinimumPath[u]+graph[u][v];
                }
        }
        
    }
    cout<<"Distance of source "<<src<<" from"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<" is "<<MinimumPath[i]<<endl;
    }

}

int main()
{
    int graph[V][V]={{0,2,0,0,5},
                    {2,0,1,2,10},
                    {0,1,0,6,3},
                    {0,2,6,0,4},
                    {5,10,3,4,0}};
    dijktras(graph,2);
}