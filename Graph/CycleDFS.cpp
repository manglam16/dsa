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

bool dfs(int i, int parent ,vector<int> arr[], vector<int> &vis){
    vis[i]=1;
    for(auto j : arr[i]){
        if(!vis[j]){
            if(dfs(j,i,arr,vis)) return true;
        }else if(i!=parent){
            return true;
        }
    }
    return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr[n+1];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		arr[v].push_back(u);
		arr[u].push_back(v);
	}
	vector<int> vis(n+1,0);
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            cout<<dfs(i,-1,arr,vis)<<" "<<i<<nline;
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