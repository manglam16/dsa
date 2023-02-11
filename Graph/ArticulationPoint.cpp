/*
    similar to bridges bur here we check for nodes and apply similar tarjan algorithm.
    only difference is for finding low we do not consider parent and vis node.
*/

int timer = 1;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &points, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (vis[it])
        {
            low[node] = min(low[node], tin[it]);
        }
        else
        {
            dfs(it, node, vis, tin, low, points, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1)
            {
                points[node] = 1;
            }
            child++;
        }
    }
    if (child > 1 && parent == -1)
        points[node] = 1;
}
vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<int> tin(V, 0);
    vector<int> low(V, 0);
    vector<int> vis(V, 0);
    vector<int> points(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(0, -1, vis, tin, low, points, adj);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (points[i] == 1)
            ans.push_back(i);
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}