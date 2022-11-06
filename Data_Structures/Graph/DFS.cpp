#include<bits/stdc++.h>
using namespace std;

class linkedList
{
    public:
    int vertex;
    linkedList* next;
};
class Graph
{
    public:
    int V;
    int E;
    linkedList** head;
};
static vector<int> Container(1);
Graph* adjList()
{
    int Vertices,Edges;
    cout<<"Enter the number of Vertices"<<endl;
    cin>>Vertices;
    cout<<"Enter the number of Edges"<<endl;
    cin>>Edges;   
    Graph* G = new Graph;    
    G->V = Vertices;
    G->E = Edges;
    G->head = new linkedList*[Vertices];
    
    for(int i=0;i<Vertices;i++)
    {
        G->head[i] = new linkedList;
        G->head[i]->vertex = i;
        G->head[i]->next = G->head[i];
    }
    int u,v;
    for(int j=0;j<Edges;j++)
    {
        cout<<"Enteredges"<<endl;
        cin>>u>>v;
        //cout<<"e";
        linkedList* node = new linkedList;
        node->vertex=v;
        node->next = G->head[u]->next;
        G->head[u]->next = node; 
    }
    return G;
}
void DFS(Graph* G,int source)
{
    Container[source]=1;
    cout<<source<<" ";
    linkedList* start = G->head[source];
    do
    {
        start=start->next;
        if(Container[start->vertex]==0)
        {
            DFS(G,start->vertex);
        }
        //Container[start->vertex]=1;
    }while(start!=G->head[source]);
}
void  dfsTraversals(Graph* G)
{
    for(int i=0;i<G->V;i++)
    {
        if(Container[i]==0)
        {
            DFS(G,i);
        }

    }
}
static queue<int> Queue;
void BFS(Graph* G,int source)
{
    Container[source]=1;
    Queue.push(source);
    linkedList* start = G->head[source];
    do
    {
        start=start->next;
        if(Container[start->vertex]==0)
        {
        Queue.push(start->vertex);
        Container[start->vertex]=1;
        
        }
    }while(start!=G->head[source]);

}
void bfsTraversals(Graph* G)
{
    for(int i=0;i<G->V;i++)
    {
        if(Container[i]==0)
            BFS(G,i);
    }
    cout<<Queue.size()<<" ";
    int a = Queue.size();
    for(int i=0;i<a;i++)
        {
            cout<<Queue.front()<<" ";
            Queue.pop();
        }

}
int main()
{
    Graph* G = adjList();  
    Container.resize(G->V,0);
    //dfsTraversals(G);

    bfsTraversals(G);
}