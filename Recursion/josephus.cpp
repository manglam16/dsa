#include <bits/stdc++.h>
using namespace std;
int ans;
void solve(int k, int i, vector<int>& v)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }
    i = (i + k) % v.size();
    v.erase(v.begin() + i);
    solve(k,i,v);
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    k=k-1;
    vector<int> v(n);
    for (int i = 1; i <=n; i++)
    {
        v[i] = i ;
    }
    int i = 0;
    solve(k, i, v);
    cout << ans<<endl;
    // for(auto i : v){
    //     cout<<i<<endl;
    // }
    
}