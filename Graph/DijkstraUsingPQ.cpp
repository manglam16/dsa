/*
    Dijkstra Algorithm used to find used to shortest distance from a node to all other nodes in a graph. Works for both directed and undirected graph.

    We use priority queue or set to find the minimum edge weight and keep relaxing the edges along it.

    problems in it:
    -it is greedy so will not look for further best in different direction.
    -Does not works on negative edge weights or negative cycles.

    time complexity - Elog(V)


*/

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {weight ,node}
    pq.push({0, S});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int weight = it.first;
        int node = it.second;
        for (auto it : adj[node])
        {
            if (dist[it[0]] > weight + it[1])
            {
                dist[it[0]] = weight + it[1];
                pq.push({weight + it[1], it[0]});
            }
        }
    }
    return dist;
}