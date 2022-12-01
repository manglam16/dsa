#include <bits/stdc++.h>
using namespace std;

// if visiting same node again and its on the same path it means it was previosly visited on the same path.

// function for checking
bool directedCycleCheck(int i, vector<int> &vis, vector<int> &pathVis, vector<int> adj[])
{
    vis[i] = 1;
    pathVis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            if (directedCycleCheck(it, vis, pathVis, adj) == true)
                return true;
        }
        else if (vis[it] && pathVis[it])
            return true;
    }
    pathVis[i] = 0;
    return false;
}

int main()
{
    // declarations
    int V;              // number of vertices
    vector<int> adj[V]; // adjacency list
    vector<int> vis;    // visited array
    vector<int> pathVis;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (directedCycleCheck(i, vis, pathVis, adj))
                return true;
        }
    }
}