#include <bits/stdc++.h>
using namespace std;

/*
    Shortest Path in Directed Acyclic Graph with weights using Topo Sort. (from a node to all the nodes in the graph)
    step 1 -  find the topo sort of the vertices and keep it stored in the staack.
    step 2 -  in dist array keep all distances as infinite initially and dist[src]=0;
    step 3 - until the stack is empty relax all the edges and you get dist array at the end.

    this means relaxing of edges :-
    if (wt + dist[i] < dist[node])
    {
        dist[node] = wt + dist[i];
    }


*/

void dfs(int i, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &s)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        int node = it.first;
        if (!vis[node])
        {
            dfs(node, adj, vis, s);
        }
    }
    s.push(i);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{

    vector<pair<int, int>> adj[N];
    vector<int> dist(N, 1e9);
    vector<int> vis(N, 0);
    stack<int> s;
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
    }
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, s);
        }
    }
    dist[0] = 0;
    while (!s.empty())
    {
        int i = s.top();
        s.pop();
        for (auto it : adj[i])
        {
            int node = it.first;
            int wt = it.second;
            if (wt + dist[i] < dist[node])
            {
                dist[node] = wt + dist[i];
            }
        }
    }
    for (auto &it : dist)
    {
        if (it == 1e9)
            it = -1;
    }
    return dist;
}
int main()
{
}