#include <bits/stdc++.h>
using namespace std;

/*
    Kahn Algorithm (BFS for finding topo sort)
    make an indegree array and if it is zero push it in .
    and while traversing removing the edges and then checking if indegree is zero until all indegrees are zero and queue is empty.
    while popping the nodes from queue we will store it in answer vector.

*/

int main()
{
    int V;
    vector<int> vis(V, 0);
    vector<int> ans;
    vector<int> adj[V];
    vector<int> inDegree(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }
}