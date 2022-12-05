#include <bits/stdc++.h>
using namespace std;

/*
topological sorting - 
linear ordering of vertices such that if there is an edge between u & v, u comes before v in the ordering.

we used a stack here to keep the very last element in dfs chain at the very first.

for cycles and undirected graph it will not be valid think with examples.

5-0
4-0
5-2
2-3
3-1
4-1

topos :
5 4 2 3 1 0
4 5 2 3 1 0
*/

void dfs(int i, stack<int> &s, vector<int> &vis, vector<int> adj[])
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
            dfs(it, s, vis, adj);
    }
    s.push(i);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> s;
    vector<int> vis(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, s, vis, adj);
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){

}