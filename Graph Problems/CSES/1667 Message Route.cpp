#include <bits/stdc++.h> 
using namespace std; 
 
void add_edge(vector<int> adj[], int src, int dest) 
{ 
	adj[src].push_back(dest); 
	adj[dest].push_back(src); 
} 
 
bool BFS(vector<int> adj[], int src, int dest, int v, 
		int pred[], int dist[]) 
{ 
 
	list<int> queue; 
	bool visited[v]; 
	for (int i = 0; i < v; i++) { 
		visited[i] = false; 
		dist[i] = INT_MAX; 
		pred[i] = -1; 
	} 
	visited[src] = true; 
	dist[src] = 0; 
	queue.push_back(src); 
 
	// standard BFS algorithm 
	while (!queue.empty()) { 
		int u = queue.front(); 
		queue.pop_front(); 
		for (auto i : adj[u]) { 
			if (!visited[i]) { 
				visited[i] = true; 
				dist[i] = dist[u] + 1; 
				pred[i] = u; 
				queue.push_back(i); 
 
				// We stop BFS when we find destination. 
				if (i == dest) return true; 
			} 
		} 
	} 
 
	return false; 
} 
 
void printShortestDistance(vector<int> adj[], int s, 
						int dest, int v) 
{ 
	int pred[v], dist[v]; 
 
	if (BFS(adj, s, dest, v, pred, dist) == false) { 
		cout << "IMPOSSIBLE\n" << endl;
		return; 
	} 
	vector<int> path; 
	int crawl = dest; 
	path.push_back(crawl); 
	while (pred[crawl] != -1) { 
		path.push_back(pred[crawl]); 
		crawl = pred[crawl]; 
	} 
	cout  << dist[dest] + 1 << endl;  
	// printing path from source to destination 
	for (int i = path.size() - 1; i >= 0; i--) 
		cout << path[i] << " "; 
} 
 
int main() 
{ 
	int n , e; 
	cin >> n >> e; 
	++n;
	vector<int> adj[n]; 
	for(int i = 0 ; i < e;++i) {
		int u , v;
		cin >> u >> v;
		add_edge( adj , u , v);
	} 
	int source = 1, dest = n-1; 
	printShortestDistance(adj, source, dest, n); 
	return 0; 
} 
