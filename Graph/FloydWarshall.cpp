/*
    Floyd Warshall Algorithm :- multi source shortest path algorithm and helps detect negative cycle as well.

    here we make an vertex*vertex sized matrix and then store shortest distance from each node to each node via all the nodes or

    dist[i][j]=min(dist[i][via]+dist[via][j],dist[i][j]);

    we do this this for all edges via all the edges. (kind off we do brute force by exploring all possible combinations of paths)

    time complexity :- O(V^3);
    if we do dijkstra for all pairs it still is O(E^2log(V)) which is better than this but does not work for negative edge.

    if negative edge then shortest path ka sense nhi bnata.


*/

// if asked to do in-place
void floyd(vector<vector<int>> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == -1)
                v[i][j] = 1e9;
        }
    }
    // main algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][k] + v[k][j] < v[i][j])
                    v[i][j] = v[i][k] + v[k][j];
            }
        }
    }
    // for negative cycle detection
    for (int i = 0; i < n; i++)
    {
        if (v[i][i] < 0)
        {
            cout << " negative cycle";
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1e9)
                v[i][j] = -1;
        }
    }
}
