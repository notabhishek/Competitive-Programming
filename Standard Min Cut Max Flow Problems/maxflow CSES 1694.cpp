// Problem: Download Speed
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1694
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 

#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = LLONG_MAX;
int n;
vector<vector<int>> cap;
vector<vector<int>> g;
vector<set<int>> setg; // to check multiple edges

int bfs(int s, int t, vector<int>& par) {
    fill(par.begin(), par.end(), -1);
    par[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v : g[u]) {
            if (par[v] == -1 && cap[u][v]) {
                par[v] = u;
                int new_flow = min(flow, cap[u][v]);
                if (v == t)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> par(n+1);
    int new_flow;

    while (new_flow = bfs(s, t, par)) {
        flow += new_flow;
        int u = t;
        while (u != s) {
            int prev = par[u];
            cap[prev][u] -= new_flow;
            cap[u][prev] += new_flow;
            u = prev;
        }
    }

    return flow;
}

void solve()
{
	int m;
	cin >> n >> m;
	g.resize(n+1);
	setg.resize(n+1);
	cap.assign(n+1, vector<int>(n+1, 0));
	for(int i=0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		if(setg[u].count(v) == 0) { // multiple pipes
			g[u].push_back(v);
			g[v].push_back(u);
			setg[u].insert(v);
			setg[v].insert(u);
		}
		cap[u][v] += c;
	}
	cout << maxflow(1, n) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        // cout << "Case #"<<tc<<": \n";
        solve();
    }
}
