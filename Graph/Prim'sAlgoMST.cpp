/*
    Prim's Algorithm for Minimum Spanning Tree. We start from any node and then put all edges in priority queue and then take the minimum and put it in mst if not visited.

    time complexity: O(Elog(V))

*/

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> vis(V, 0);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //{weight,{node,parent}}
    pq.push({0, {0, -1}});
    vector<pair<int, int>> mst;
    int sum = 0;
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if (vis[node])
            continue;
        if (parent != -1)
        {
            if (!vis[node])
            {
                vis[node] = 1;
                sum += wt;
                mst.push_back({node, parent});
            }
        }
        else
            vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it[0]])
                continue;
            else
                pq.push({it[1], {it[0], node}});
        }
    }
    return sum;
}