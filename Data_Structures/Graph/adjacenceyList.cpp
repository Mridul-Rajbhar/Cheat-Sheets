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
void print(Graph* G)
{
    for(int i=0;i<G->V;i++)
    {
        linkedList* temp = G->head[i];
        do
        {
            cout<<temp->vertex<<"-->";
            temp=temp->next;
        } while (temp!=G->head[i]);
        cout<<"NULL"<<endl;
    }
}
int main()
{
    Graph* G = adjList();
    print(G);
}