#include<iostream>
using namespace std;

class Graph
{
    public:
    int V;
    int E;
    int **Adj;
};

Graph* Matrix()
{
    int Vertices,Edges;
    cout<<"Enter number of Vertices"<<endl;
    cin>>Vertices;
    cout<<"Enter number of Edges"<<endl;
    cin>>Edges;
    Graph* G= new Graph;
    G->V = Vertices;
    G->E = Edges;
    G->Adj = new int*[Vertices];
    for(int i=0;i<Vertices;i++)
        G->Adj[i]=new int[Vertices];
    for(int i=0;i<G->V;i++)
    {
        for(int j=0;j<G->V;j++)
        {
            if(i==j)
                G->Adj[i][j]=1;
            else
                G->Adj[i][j]=0;
        }
    }

    int u,v;
    for(int i=0;i<G->E;i++)
    {
        cout<<"Enter the edges"<<endl;
        cin>>u>>v;
        cout<<endl;
        G->Adj[u][v]=1;
        G->Adj[v][u]=1;
    }
    return G;
}
void print(Graph* G)
{
    for(int i=0;i<G->V;i++)
    {
        for(int j=0;j<G->V;j++)
        {
            cout<<G->Adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Graph* object = Matrix();
    print(object);
}