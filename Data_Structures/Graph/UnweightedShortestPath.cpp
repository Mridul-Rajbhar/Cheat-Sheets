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

vector<pair<int,int>> Table(1);
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
    Table.resize(G->V);

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

void UnweightedPath(Graph* G,int start)
{
    queue<int> Queue;
    Queue.push(start);
    for(int i=0;i<G->V;i++)
    {
            Table[i].first = -1;
    }
    Table[start].first = 0;
    int current=start;
    while(!Queue.empty())
    {
        Queue.pop();
        linkedList* S=G->head[current];
        do
        {
            S=S->next;
            if(S!=G->head[current] && (Table[S->vertex].first==-1))
            {
                Queue.push(S->vertex);
                Table[S->vertex].first=Table[current].first+1;
                Table[S->vertex].second = current;
            }
        } while(S!=G->head[current]);
        if(!Queue.empty())
            current = Queue.front();
    }

}

int main()
{
    Graph *G =adjList();
    /*
    int start = 2;
    UnweightedPath(G,start);
    for(int i=0;i<G->V;i++)
    {
        if(i!=start)
            cout<<"Distance of node "<<i<<" From "<<start<<" is "<<Table[i].first<<" and previous node is "<<Table[i].second;
        cout<<endl;
    }
    */


}