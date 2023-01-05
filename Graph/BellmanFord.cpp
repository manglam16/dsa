/*
    Bellman ford single sourse shortest path algorithm like dijkstra but works for negative edges as well but not on negative cycle and only works for directed graph. to use in undirected graph first convert it to directed graph.

    we relax all the edges for n-1 times.

    relax means :
    if(dist[u]+wt<dist[v] && dist[u]!=INT_MAX) dist[v] = dist[u]+wt;

    why n-1?
    because in worst case we will need n-1 iterations to reach n-1 edges.

    how detect negative cycle?
    if at nth iteration value of dist array gets updated this means graph has negative cycle.

    time complexity : O(V*E)
*/

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            if (dist[u] == INT_MAX)
                continue;
            if (dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    // for checking of negative edge
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        if (dist[u] == INT_MAX)
            continue;
        if (dist[u] + weight < dist[v])
            return {-1};
    }
    return dist;
}
