#define int int64_t
const int INF = 1e18;
int N;
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
                if (v == t) return new_flow;
                q.push({v, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> par(N+1);
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

void dfs(int s, vector<int> &vis) {
	vis[s] = 1;
	for(auto v : g[s]) {
		if(!vis[v] && cap[s][v] > 0) dfs(v, vis);
	}
}

void findMinCut() {
	// call maxflow before running this 
	vector<int> vis(N + 1, 0); // everything in set 2
	dfs(1, vis);
	vector<pair<int,int>> minCutEdges;
	for(int u = 1; u <= N; ++u) {
		for(int v : g[u]) {
			if(vis[u] != vis[v] && cap[u][v] == 0) 
				minCutEdges.push_back({u,v});
		}
	}
	for(auto &i : minCutEdges) cout << i.ff << " " << i.ss << "\n";
}

void solve()
{
	int n, m;
	cin >> n >> m;
	N = n;
	g.resize(N+1);
	setg.resize(N+1);
	cap.assign(N+1, vector<int>(N+1, 0));
	for(int i=0; i < m; ++i) {
		int u, v, c = 1;
		cin >> u >> v;
		if(setg[u].count(v) == 0) { // multiple pipes
			g[u].push_back(v);
			g[v].push_back(u);
			setg[u].insert(v);
			setg[v].insert(u);
		}
		cap[u][v] += c;
		cap[v][u] += c; // remove this for directed edge
	}
	
	cout << maxflow(1, n) << "\n";
	findMinCut();
}
