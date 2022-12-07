#include <bits/stdc++.h>
using namespace std;

/*
    Cycle Dtetection Of Directed Graph using BFS Kahn Algorithm
    if topo sort contains all n elements it will be Acyclic else it will be cyclic because topo sort
    is not able to be completed
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
    if (ans.size() == V)
        cout << "acyclic";
    else
        cout << "cyclic";
}