/*
    start doing bfs from source in dist array and dist[src]=0;
*/

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(N, INT_MAX);
    queue<pair<int, int>> q;
    dist[src] = 0;
    q.push({src, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int node = it.first;
        int dis = it.second;
        for (auto i : adj[node])
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = dis + 1;
                q.push({i, dis + 1});
            }
        }
    }

    for (auto &it : dist)
    {
        if (it == INT_MAX)
            it = -1;
    }
    return dist;
}