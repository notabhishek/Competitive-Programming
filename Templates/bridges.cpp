#include<bits/stdc++.h>
using namespace std;


const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];

vector<int> in( MAXN );
vector<int> low( MAXN );
vector<  pair<int , int >> bridges;
int timer = 0;
 
void fBridges(int src , int p , vector< bool > &vis ) {
	vis[src] = true;
	in[src] = low[src] = timer++;
	for(auto &to : adj[src]) {
		if(to == p ) continue;
		if(vis[to]) {
			low[src] = min( low[src] , in[to] ); // backedge 
		} else {
			fBridges(to , src , vis);
			if(low[to] > in[src]) {
				bridges.push_back({ src , to });
			}
			low[src] = min( low[src] , low[to] );
		}
	}
}

void findBridges(int n){
	vector< bool > vis( n + 1 , false);
	for(int node = 1; node <= n; ++node ) {
		if( !vis[node] ) {
			fBridges(node , -1 , vis );
		}
	}
}


int32_t main() {
	int n , m;
	cin >> n >> m;
	
	
	timer = 0;
	for(int i = 0 ; i <= n; ++i) adj[i].clear();
	bridges.clear();
	
	while(m--) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	findBridges(n);
	
	for(auto &i : bridges) 
		cout << i.first << " -- " << i.second << "\n";
}