#include<bits/stdc++.h>
using namespace std;

#define int int64_t

using pii = pair<int , int>;

const int INF = 1e15;
const int MAXN = 1e5 + 1;
vector< pair<int , int>> adj[MAXN];
vector<int> p , d;


// Dijkstra using PriorityQueue
void dijkstra(int s , int n) {
	p.assign(n + 1, -1);
	d.assign(n + 1, INF);
	
	priority_queue<pii, vector<pii>, greater<pii> > q;
	d[s] = 0;
	q.push({ 0 , s});
	while(!q.empty()) {
		pii tp = q.top(); q.pop();
		int v = tp.second , d_v = tp.first;
		
		if(d_v != d[v] ) continue;
		 
		for(auto &edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;
			
			if( d[v] + len < d[to] ) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to] , to});
			}
		}
	}
}

void path(int v) {
	vector<int> res;
	if(d[v] == INF) {
		cout << "-1 \n";
		// return res; // unreachable
	}
	while(v != -1) {
		res.push_back(v);
		v = p[v];
	}
	reverse(res.begin() , res.end());
	for(auto &i : res) cout << i << "->"; cout << "\n";
	// return res;
}



int32_t main() {
	int n , m;
	cin >> n >> m;
	for(int i = 0 ; i < m; ++i) {
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	dijkstra(1 , n);
	
	cout << "D : "; for(int i = 1; i <= n; ++i ) cout << d[i] << " "; cout << "\n";
	cout << "P : "; for(int i = 1; i <= n; ++i ) cout << p[i] << " "; cout << "\n";
	
	int v = 5;
	path(v);
	path(3);
	path(4);
}