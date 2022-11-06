#include<bits/stdc++.h>

using namespace std;
class edge
{
    public:
    int src, des;
};

class graph
{
    public:
    int v, e;
    edge *edges;
};

graph *createGraph(int v, int e)
{
    graph *g = new graph();
    g->v = v;
    g->e = v;
    g->edges = new edge[e];
    return g;
}

void unionFunc()
{

}

int find()
{

}


int main()
{
    int v,e;
    cout<<"Enter the vertices and edges"<<endl;
    cin>>v>>e;
    graph *g = createGraph(v,e);

    return 0;
}