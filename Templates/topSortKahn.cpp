#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
vector<int> tsort;
int din[ MAXN ];

void kahn(int n) {
	queue<int > q;
	for(int i = 1 ; i <= n; ++i) 
		if( din[i] == 0 ) 
			q.push(i);
	while(!q.empty()) {
		int cur = q.front();
		tsort.push_back(cur);
		q.pop();
		
		for(int node : adj[cur]) {
			din[node]--;
			if(din[node] == 0) 
				q.push(node);
		}
	}
} 

int32_t main() {
	int n , m;
	cin >> n >> m;
	
	for(int i = 0 ; i <= n; ++i) 
		adj[i].clear() , din[i] = 0;
	tsort.clear();
	
	for(int i = 0 ; i < m; ++i) {
		int u , v; 
		cin >> u >> v;
		adj[u].push_back(v);
		din[v]++;
	}
	
	kahn(n);
	
	
	if( (int)tsort.size() == n ) {
		cout << "Topsort : "; for(auto &i : tsort ) cout << i << " "; cout << "\n";
	} else {
		cout << "Topsort doesn't exist\n";
	}
}