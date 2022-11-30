#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int INF = 1e9;
const long long int LINF = 1e18;

#define pb push_back
#define ll long long
#define nline "\n"
#define double long double
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define set_bits __builtin_popcountll

bool checkBipartitebfs(int node, vector<int> arr[], vector<int> &vis)
{
    queue<int> q;
    vis[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto j : arr[temp])
        {
            if (vis[j] == -1)
            {
                vis[j] = 1 - vis[temp];
                q.push(j);
            }
            else if (vis[j] == vis[temp])
            {
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
    vector<int> vis(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            if (!checkBipartitebfs(i, arr, vis))
            {
                cout << "GOOD HAI JI" << i << nline;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
    }
}