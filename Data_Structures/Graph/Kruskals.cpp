#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class unionFind
{
public:
    int *parent;
    int *rank;

    unionFind(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class graph
{
public:
    int V;
    vector<vector<int>> edges;
    vector<pair<int, int>> srcDes;
    vector<int> distances;

    graph(int n)
    {
        this->V = n;
    }
    void addEdge(int src, int dest, int wht)
    {
        edges.push_back({wht, src, dest});
    }

    void kruskals()
    {
        sort(edges.begin(), edges.end());
        unionFind uf(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][1];
            int y = edges[i][2];
            int w = edges[i][0];
            if (uf.find(x) != uf.find(y))
            {
                uf.Union(x, y);
                srcDes.push_back(make_pair(x, y));
                distances.push_back(w);
                //cout << w << " ";
            }
        }
    }

    void printDistances()
    {
        for (int i = 0; i < distances.size(); i++)
        {
            cout << srcDes[i].first << " to " << srcDes[i].second << " cost is " << distances[i] << endl;
        }
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

    g.kruskals();
    g.printDistances();

    return 0;
}