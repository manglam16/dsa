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

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr[n];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		arr[v].push_back(u);
		arr[u].push_back(v);
	}
	int vis[n] = {0};
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 0)
		{
			//bfs function
			queue<int> q;
			q.push(i);
			vis[i] = 1;
			while (!q.empty())
			{
				int temp = q.front();
				vis[temp] = 1;
				q.pop();
				for (auto j : arr[temp])
				{
					if (vis[j] == 0)
					{
						q.push(j);
						vis[j] = 1;
					}
				}
				cout << temp << " ";
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