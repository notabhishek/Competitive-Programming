#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> col;

const int maxn = 2e5 + 10;
set<int> st[maxn];
int res[maxn];

// runs in Nlog^2(N)
void dfs(int u, int p) {
	st[u].insert(col[u]);
	for(auto &v: g[u]) {
		if( v!=p ) {
			dfs(v, u);
			
			// swap in O(1) for logn amortized
			if(st[u].size() < st[v].size()) swap(st[u], st[v]);
			for(auto &j : st[v]) { 
				st[u].insert(j); // merge
			}
			st[v].clear();
		}
	}
	res[u] = st[u].size();
}

void solve()
{
	cin >> n;
	col.resize(n+1);
	g.resize(n+1);
	for(int i = 1; i <= n; ++i) cin >> col[i];
	for(int i = 1; i <n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1, 0);	
	for(int i = 1; i<=n; ++i) cout << res[i] << " ";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        solve();
    }
}
