#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int n;
vector<vector<int>> g;
vector<int> col;

// initialize data structures here 
const int maxn = 2e5 + 10;
map<int, int> f[maxn];
set<pair<int,int>> st[maxn];
int sum[maxn];
int res[maxn];

// runs in Nlog^2(N) 
void dfs(int u, int p) {
	// add current node to ds
	f[u][col[u]]++;
	sum[u] = col[u];
	st[u].insert({1, col[u]});
	
	for(auto &v: g[u]) {
		if( v!=p ) {
			dfs(v, u);
			
			// swap in O(1) for logn amortized | use a.swap(b) for pbds, array
			if(st[u].size() < st[v].size()) {
				swap(st[u], st[v]);
				swap(f[u], f[v]);
				swap(sum[u], sum[v]);
			}
			
			// merge child here 
			for(auto &j : f[v]) {
				if(st[u].find({f[u][j.first], j.first}) != st[u].end()) {
					st[u].erase({f[u][j.first], j.first});
				} else {
					sum[u] += j.first;
				}
				f[u][j.first] += j.second;
				st[u].insert({f[u][j.first], j.first});
			}
			
			// clear child
			st[v].clear();
			f[v].clear();
			sum[v] = 0;
		}
	}
	
	// solve query here
	int maxf = st[u].rbegin()->first;
	while(st[u].begin()->first < maxf) {
		sum[u] -= st[u].begin()->second;
		st[u].erase(st[u].begin());
	}
	res[u] = sum[u];
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
