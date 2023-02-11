/*
    bridge in graph : any edge on whose removal will increase number of components.
    print all the bridges is the question.
    we use two arrays tin(time of insertion) and low(which is lowest tin of all adjacent edges apart from
    parent).
    and check for each edge if we can reach it using other way or not using low array.
*/

int timer = 1;
void dfs(int node, int parent, vector<int> &tin, vector<int> &vis, vector<int> &low, vector<int> adj[], vector<vector<int>> &bridges)
{
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (vis[it] == 0)
        {
            dfs(it, node, tin, vis, low, adj, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            low[node] = min(low[it], low[node]);
        }
    }
}
vector<vector<int>> bridgesInGraph(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> bridges;
    vector<int> adj[n];
    vector<int> tin(n);
    vector<int> vis(n, 0);
    vector<int> low(n);
    for (auto it : connections)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, tin, vis, low, adj, bridges);
    return ans;
}