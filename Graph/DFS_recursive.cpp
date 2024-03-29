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

void dfs(int i, vector<int> arr[], vector<int> &vis, vector<int> &storeDfs) {
	storeDfs.pb(i);
	vis[i] = 1;
	for (auto j : arr[i]) {
		if (!vis[j]) {
			dfs(j, arr, vis, storeDfs);
		}
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr[n + 1];
	vector<int> vis(n + 1, 0);
	vector<int> storeDfs;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		arr[u].pb(v);
		arr[v].pb(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i]) {
			dfs(i, arr, vis, storeDfs);
		}
	}

	for (auto i : storeDfs) {
		cout << i << nline;
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