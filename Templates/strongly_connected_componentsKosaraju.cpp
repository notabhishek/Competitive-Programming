#include<bits/stdc++.h>
using namespace std;
#define int int64_t 

const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
vector<int> tadj[MAXN];

vector<int> vis;
vector<int> order;
int comp[MAXN];
int sccs = 0;
vector< vector< int > >  SCC;

void dfsOrder(int src) {
	vis[src] = true;
	for(auto to : adj[src] ) {
		if(!vis[to]) {
			dfsOrder(to);
		}
	}
	order.push_back(src);
}

// dfs on transpose
void dfsSCC(int src) {
	vis[src] = true;
	for(auto to : tadj[src]) {
		if(!vis[to]) {
			dfsSCC(to);		
		}
	}
	comp[ src ] = sccs;
	SCC[ sccs ].push_back( src );
}

void kosaraju(int n) {
	order.clear();
	vis.assign(n + 1 , false);
	
	for(int node = 1 ; node <= n; ++node )
		if(!vis[node]) 
			dfsOrder(node);
	
	SCC.clear();
	sccs = 0;
	
	vis.assign(n+1 , false);
	for(int i = 1; i <= n; ++i ) {
		if(!vis[ order[n - i] ])  {
			SCC.push_back(vector<int> ());
			dfsSCC( order[ n - i ]);
			++sccs;
		}
	}
	
	cout << "Total components  : " << sccs << "\n";
	cout << "Components : \n";
	for(auto &i : SCC) {
		for(auto &j : i) cout << j << " "; cout << " "; cout << "\n";
	}
	cout << "Component Numbers : \n";
	for(int i = 1; i <= n; ++i) cout << comp[i] << " "; cout << "\n";
}

int32_t main() {
	int n , m ;
	cin >> n >> m;
	
	for(int i = 0 ; i < m; ++i) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		tadj[v].push_back(u);
	}
	
	kosaraju(n);
	
}