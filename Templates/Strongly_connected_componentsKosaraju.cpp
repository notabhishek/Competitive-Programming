// strongly connected components, condensation graph
#include<bits/stdc++.h>
using namespace std;
#define int int64_t 

const int MAXN = 1e5 + 1;
vector<int> g[MAXN];
vector<int> tg[MAXN];

vector<int> vis;
vector<int> order;
int comp[MAXN];
int sccs = 0;
vector< vector< int > >  SCC;

// for condensation graph
vector<int> roots;
vector<int> root_nodes;
vector<vector<int>> cg;


void dfsOrder(int src) {
	vis[src] = true;
	for(auto to : g[src] ) {
		if(!vis[to]) {
			dfsOrder(to);
		}
	}
	order.push_back(src);
}

// dfs on transpose
void dfsSCC(int src) {
	vis[src] = true;
	for(auto to : tg[src]) {
		if(!vis[to]) {
			dfsSCC(to);		
		}
	}
	comp[ src ] = sccs;
	SCC[ sccs ].push_back( src );
}

void kosaraju(int n) {
	order.clear();
	vis.assign(n+1, false);
	roots.assign(n+1, 0);
	root_nodes.clear();
	cg.clear(); cg.resize(n+1);
	
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
			
			int root = SCC[sccs].front(); root_nodes.push_back(root);
			for(auto &x : SCC[sccs]) roots[x]=root;
			
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
	
	// Condensation graph
	for(int u = 1; u <= n; ++u) {
		for(auto &v: g[u]) {
			if(roots[u] != roots[v]) 
				cg[roots[u]].push_back(roots[v]);
		}
	}
	cout << "root nodes : "; for(auto &i: root_nodes) cout << i << " "; cout << "\n";
	cout << "roots : "; for(auto &i: roots) cout << i << " "; cout << "\n";
	cout << "condensation graph: \n";
	for(int i = 1; i <= n; ++i) {
		cout << i << ": "; for(auto &j : cg[i]) cout << j << " "; cout << "\n";
	}
}

int32_t main() {
	int n , m ;
	cin >> n >> m;
	
	for(int i = 0 ; i < m; ++i) {
		int u , v;
		cin >> u >> v;
		g[u].push_back(v);
		tg[v].push_back(u);
	}
	
	kosaraju(n);
}

/*
Input:
8 12
1 2
2 3
3 1
2 8
3 4
8 4
4 8
7 8
5 4
5 7
7 6
6 5

Output:
Total components  : 3
Components : 
7 6 5  
2 3 1  
8 4  
Component Numbers : 
1 1 1 2 0 0 0 2 
root nodes : 7 2 8 
roots : 0 2 2 2 8 7 7 7 8 
condensation graph: 
1: 
2: 8 8 
3: 
4: 
5: 
6: 
7: 8 8 
8: 
*/
