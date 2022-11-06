#include <bits/stdc++.h>
using namespace std;

void makeset(int *parent, int *rank, int s)
{
    for (int i = 0; i < s; i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }
}

int find_by_path_compression(int *parent, int s, int ele)
{
    if (ele < 0 || ele >= s)
    {
        return -1;
    }
    if (parent[ele] == ele)
    {
        return ele;
    }
    else
    {
        return (parent[ele] = find_by_path_compression(parent, s, parent[ele]));
    }
}

void union_by_height(int *parent, int *rank, int s, int ele1, int ele2)
{
    int root1 = find_by_path_compression(parent, s, ele1);
    int root2 = find_by_path_compression(parent, s, ele2);

    cout << root1 << " " << rank[root1] << " " << root2 << " " << rank[root2] << endl;
    if ((root1 == root2) || (root1 == -1 || root2 == -1)) //both values are equal and not in same set
    {
        return;
    }

    if (rank[root2] < rank[root1])
    {
        parent[root2] = root1;
    }
    else if (rank[root1] < rank[root2])
    {
        parent[root1] = root2;
    }
    else
    {
        parent[root1] = root2;
        rank[root2]++;
    }
}

void union_by_weight(int *parent, int *rank, int s, int ele1, int ele2)
{
    int root1 = find_by_path_compression(parent, s, ele1);
    int root2 = find_by_path_compression(parent, s, ele2);

    cout << "root 1: " << root1 << " size:" << rank[root1] << " root2: " << root2 << " size:" << rank[root2] << endl;
    if ((root1 == root2) || (root1 == -1 || root2 == -1))
    {
        return;
    }

    if (rank[root1] < rank[root2])
    {
        parent[root1] = parent[root2];
        rank[root2] += rank[root1];
    }
    else
    {
        parent[root2] = parent[root1];
        rank[root1] += rank[root2];
    }
}

void print(int *parent, int *rank, int s)
{
    cout << "index:   ";
    for (int i = 0; i < s; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "parent:  ";
    for (int i = 0; i < s; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
    cout << "size:    ";
    for (int i = 0; i < s; i++)
    {
        cout << rank[i] << " ";
    }
    cout << endl;
}

int main()
{
    int s = 6;
    int *parent, *rank;
    parent = new int[s];
    rank = new int[s];
    makeset(parent, rank, s);
    print(parent, rank, s);

    //---------Union by height (rank on basis of height)-------------

    union_by_height(parent, rank, s, 1, 2); // Attach 1 to 2
    union_by_height(parent, rank, s, 0, 3);
    union_by_height(parent, rank, s, 1, 3);
    print(parent, rank, s);

    //---------- Union by weight (rank on basis of size) ------------

    union_by_weight(parent, rank, s, 0, 1); //Attach 2 to 1
    union_by_weight(parent, rank, s, 1, 2);
    union_by_weight(parent, rank, s, 3, 2);
    print(parent, rank, s);
    // union_by_weight(arr, size, 3,0);

    return 0;
}