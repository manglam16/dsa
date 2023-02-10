/*
    Disjoint set also known as union find : different data structure used to find weather two nodes are part of same component or not.
    main two functions :
    union : which is used to add the edge to this data structure.
    find ultimate parent : used to find the ultimate parent.
    both these operations are approximately constant (O(4*α)) difficult mathematical proof.

    union by rank : here joining is decided by ranking of the different components.
    union by size : same thing is decided by size of components.
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return parent[node];
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) // smaller attached to one with larger rank
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) // since size gets larger rank is increased
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
    // example on how to use it
    DisjointSet ds(7); // a 7 node sized disjoint set it made
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findUParent(3) == ds.findUParent(7)) // if same they are joined else not
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionByRank(3, 7); // dynaminc nature of graph

    if (ds.findUParent(3) == ds.findUParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}