/*
    here we store previous path using a parent or camefrom array and then backtrack to find the path.

*/

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{

    vector<int> ans;
    vector<pair<int, int>> adj[n + 1];
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{distance,node}
    dist[1] = 0;
    pq.push({0, 1});
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    for (int i = 0; i < n + 1; i++)
    {
        parent[i] = i;
    }

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            if (dist[it.first] > weight + it.second)
            {
                dist[it.first] = weight + it.second;
                pq.push({weight + it.second, it.first});
                parent[it.first] = node;
            }
        }
    }
    int node = n;
    while (parent[node] != node)
    {
        ans.push_back(node);
        node = parent[node];
    }
    if (ans.size() == 0)
        return {-1};
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
}