#include<bits/stdc++.h>
using namespace std;


const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];

vector<int> in( MAXN );
vector<int> low( MAXN );
vector<int> isArt;
set<int> artPts;
int timer = 0;
 
void fArtPts(int src , int p, vector< bool > &vis ) {
	vis[src] = true;
	in[src] = low[src] = timer++;
	int children = 0;
	for(auto &to : adj[src]) {
		if(to == p ) continue;
		if(vis[to]) {
			low[src] = min( low[src] , in[to] ); // backedge 
		} else {
			fArtPts(to , src , vis);
			if(low[to] >= in[src] && p!=-1 ) {
				artPts.insert(src);
				isArt[src] = true;
			}
			low[src] = min( low[src] , low[to] );
			++children;
		}
	}
	if(p==-1 && children >= 2) {
		artPts.insert(src);
		isArt[src] = true;
	}
}

void findArtPts(int n) {
	vector< bool > vis( n + 1 , false);
	for(int node = 1; node <= n; ++node ) {
		if( !vis[node] )
			fArtPts(node , -1 , vis);
	}
}


int32_t main() {
	int n , m;
	cin >> n >> m;
	
	
	timer = 0;
	for(int i = 0 ; i <= n; ++i) adj[i].clear();
	artPts.clear();
	isArt.assign(n+1 , false );
	
	while(m--) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	findArtPts(n);
	
	cout << "pts : "; for(auto &i : artPts) cout << i << " "; cout << "\n";
	cout << "all  : "; for(int i = 1; i <= n; ++i) cout << isArt[i] << " "; cout << "\n";
}