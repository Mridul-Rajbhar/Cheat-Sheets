#include <bits/stdc++.h>
using namespace std;
class linkedList
{
public:
    int vertex;
    linkedList *next;
};
class Graph
{

public:
    int V;
    int E;
    linkedList **head;
};
Graph *adjList()
{
    int Vertices, Edges;
    cout << "Enter the number of Vertices" << endl;
    cin >> Vertices;
    cout << "Enter the number of Edges" << endl;
    cin >> Edges;
    Graph *G = new Graph;
    G->V = Vertices;
    G->E = Edges;
    G->head = new linkedList *[Vertices];
    for (int i = 0; i < Vertices; i++)
    {
        G->head[i] = new linkedList;
        G->head[i]->vertex = i;
        G->head[i]->next = G->head[i];
    }
    int u, v;
    for (int j = 0; j < Edges; j++)
    {
        cout << "Enteredges" << endl;
        cin >> u >> v;
        linkedList *node = new linkedList;
        node->vertex = v;
        node->next = G->head[u]->next;
        G->head[u]->next = node;
    }
    return G;
}
void Topological(int source, vector<int> &Visit, stack<int> &S, Graph *G, vector<int> &LP)
{
    Visit[source] = 1;
    linkedList *start = G->head[source];
    do
    {
        start = start->next;
        if (start->vertex > source)
        {
            LP[start->vertex] = max(LP[source] + 1, +LP[start->vertex]);
        }
        if (Visit[start->vertex] == 0)
        {
            Topological(start->vertex, Visit, S, G, LP);
        }
    } while (start != G->head[source]);
    S.push(source);
}

void TopologicalSort(Graph *G)
{
    vector<int> LP(1);
    LP.resize(G->V, 0);
    vector<int> Visited(1);
    Visited.resize(G->V, 0);
    stack<int> Stack;
    for (int i = 0; i < G->V; i++)
    {
        if (Visited[i] == 0)
        {
            Topological(i, Visited, Stack, G, LP);
        }
    }
    int n = Stack.size();
    for (int i = 0; i < n; i++)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << LP[i] << " ";
    }
}
void print(Graph *G)
{
    for (int i = 0; i < G->V; i++)
    {
        linkedList *temp = G->head[i];
        do
        {
            cout << temp->vertex << "-->";
            temp = temp->next;
        } while (temp != G->head[i]);
        cout << "NULL" << endl;
    }
}
int main()
{
    Graph *G = adjList();
    print(G);
    cout << endl;
    TopologicalSort(G);
}