/*
    for the same node if better option comes up it removes it from set there itself instead iterating on it like priority queue. but it needs extra log(n) for erase but saves further iterations.
    so set and priority queue are kind off similar to each other.
*/

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    set<pair<int, int>> st;
    st.insert({0, S});
    while (!st.empty())
    {
        auto it = *(st.begin());
        st.erase(it);
        int weight = it.first;
        int node = it.second;
        for (auto i : adj[node])
        {
            if (weight + i[1] < dist[i[0]])
            {
                if (dist[i[0]] != INT_MAX)
                {
                    st.erase({dist[i[0]], i[0]});
                }
                dist[i[0]] = weight + i[1];
                st.insert({dist[i[0]], i[0]});
            }
        }
    }
    return dist;
}