#include<bits/stdc++.h>
using namespace std;

const int NX = 1e5 + 10;
int n;
set<int> g[NX];
int par[NX]; // par in centroid decomposition 
int sub[NX]; // subtree siz

// calculate subtree sizes 
int dfs1(int u, int p) {
	sub[u] = 1;
	for(int v: g[u]) 
		if(v!=p)
			sub[u] += dfs1(v, u);
	return sub[u];
}

// find the centroid
int dfs(int u, int p, int sz) {
	for(int v : g[u]) {
		if(v != p && sub[v] > sz/2) 
			return dfs(v, u, sz);
	}
	return u;   
}

// decompose the tree
void decompose(int u, int p) {
	int subsz = dfs1(u, -1);
	int ctd = dfs(u, p, subsz);
	cout << "tree rooted at "<< u << " with sz "<< subsz << " has centroid " << ctd << endl;
	par[ctd] = p;
	for(int v : g[ctd]) {
		g[v].erase(ctd);
		decompose(v, ctd);
	}
}

int main() {
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}	
	
	decompose(1, -1);
	
	return 0;
}
