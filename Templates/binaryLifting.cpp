#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
vector< int > adj[MAXN];
int N , L;
int timer = 0;
vector <int> tin , tout;
vector < vector < int >> up;

void timeDfs(int src , int p) {
	tin[src] = ++timer;
	up[src][0] = p;
	for(int i = 1; i <= L; ++i) {
		up[src][i] = up[ up[src][i-1] ][i-1];
	}
	
	for(auto &to : adj[src]) {
		if( to != p )
			timeDfs(to , src);
	}
	
	tout[src] = ++timer;
}

bool isAnc(int u  , int v) {
	// check if u is ancestor of v
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u , int v) {
	if ( isAnc(u , v ) ) 
		return u;
	if( isAnc(v , u ) )
		return v;
	
	for(int i = L; i>= 0; --i) {
		if( !isAnc(up[u][i] , v ) ) 
			u = up[u][i];
	}
	return up[u][0];
}

void init(int root = 1) {
	tin.resize(N + 1);
	tout.resize(N + 1);
	timer = 0;
	L = ceil(log2(N));
	up.assign(N + 1 , vector< int > (L + 1) );
	timeDfs(root , root);
}
int32_t main() {

	cin >> N;
	for(int i = 1 ; i < N; ++i ) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	init(1);
	cout << LCA(4 , 5) << endl;
	
}