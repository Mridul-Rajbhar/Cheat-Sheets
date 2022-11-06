#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int destination;
    int cost;
};
class Graph
{
public:
    int n;
    list<node> *adjList;

    void showList(int src, list<node> lt)
    {
        list<node>::iterator i;
        node tempNode;
        for (i = lt.begin(); i != lt.end(); i++)
        {
            tempNode = *i;
            cout << src << " to " << tempNode.destination << " cost is " << tempNode.cost << endl;
        }
        cout << endl;
    }

    Graph()
    {
        n = 0;
    }
    Graph(int nodeCount)
    {
        n = nodeCount;
        adjList = new list<node>[n];
    }

    void addEdge(int source, int dest, int cost)
    {
        node newNode1;
        newNode1.destination = dest;
        newNode1.cost = cost;
        adjList[source].push_back(newNode1);

        node newNode2;
        newNode2.destination = source;
        newNode2.cost = cost;
        adjList[dest].push_back(newNode2);
    }

    void displayEdges()
    {
        for (int i = 0; i < n; i++)
        {
            list<node> tempList = adjList[i];
            showList(i, tempList);
        }
    }
};
void dijkstras(Graph g, int start)
{
    int n = g.n;
    set<node> S;
    vector<int> dist(n, INT_MAX);

    while (!S.empty())
    {
        list<int>::iterator i;
        i = min_element(Q.begin(), Q.end());
        int u = *i;
        Q.remove(u);
        S.insert(u);
        list<node>::iterator it;

        for (it = g.adjList[u].begin(); it != g.adjList[u].end(); it++)
        {
            if ((dist[u] + (it->cost)) < dist[it->destination])
            {
                dist[it->destination] = (dist[u] + (it->cost));
                prev[it->destination] = u;
            }
        }
    }
}
int main()
{
    int n = 7;
    Graph g(n);
    int dist[7], prev[7];
    int start = 3;

    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 0, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 1, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 6, 4);
    g.addEdge(4, 2, 4);
    g.addEdge(4, 3, 2);
    g.addEdge(4, 5, 2);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 2, 2);
    g.addEdge(5, 4, 2);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 3, 4);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 5, 1);

    dijkstras(g, start);
    g.displayEdges();
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (i != start)
            cout << start << " to " << i << ", Cost: " << dist[i] << " Previous: " << prev[i] << endl;
    }
}