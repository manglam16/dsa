/*
    only in directed graph.
    Strongly connected components or (scc) : is a component in which every node is reachable from every node.
    to find number of scc or print the scc we use kosaraju algorithm.
    step1 : sort the edges according to finishing time in stack.
    step2 : reverse the edges.
    step3 : according to stack find how many dfs can be done. these many scc exist in graph.
*/

void dfs1(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    if (vis[node])
        return;
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs1(it, vis, adj, st);
        }
    }
    st.push(node);
}
void dfs2(int node, vector<int> &vis, vector<int> reverseAdj[])
{
    if (vis[node])
        return;
    vis[node] = 1;
    for (auto it : reverseAdj[node])
    {
        if (!vis[it])
        {
            dfs2(it, vis, reverseAdj);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    vector<int> reverseAdj[V];
    int ans = 0;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int u = it;
            int v = i;
            reverseAdj[u].push_back(v);
        }
    }
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs1(i, vis, adj, st);
        }
    }
    for (auto &it : vis)
        it = 0;
    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if (vis[i])
            continue;
        else
        {
            dfs2(i, vis, reverseAdj);
            ans++;
        }
    }
    return ans;
}