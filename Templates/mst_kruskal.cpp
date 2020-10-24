vector<int> parent, Rank;

void make_set(int v) {
    parent[v] = v;
    Rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
ostream& operator<<(ostream& os, const Edge &e) {
    	os << "[ (" << e.u << " - " << e.v << ") , " << e.weight << " ] ";
    	return os;
}



int n;
vector<Edge> edges;

// 0 based indexing of nodes ie. 0 to n-1
int kruskal() {
	int cost = 0;
	vector<Edge> MST;
	parent.resize(n);
	Rank.resize(n);
	for (int i = 0; i < n; i++)
	    make_set(i);
	
	sort(edges.begin(), edges.end());
	
	for (Edge e : edges) {
	    if (find_set(e.u) != find_set(e.v)) {
	        cost += e.weight;
	        MST.push_back(e);
	        union_sets(e.u, e.v);
	    }
	}
	
	cout << "cost : " << cost << endl;
	// cout << "Edges : " << MST;
	return cost;
}

// 1 based indexing of nodes ie. 1-n
int kruskal() {
	int cost = 0;
	vector<Edge> MST;
	parent.resize(n + 1);
	Rank.resize(n + 1);
	for (int i = 1; i <= n; i++)
	    make_set(i);
	
	sort(edges.begin(), edges.end());
	
	for (Edge e : edges) {
	    if (find_set(e.u) != find_set(e.v)) {
	        cost += e.weight;
	        MST.push_back(e);
	        union_sets(e.u, e.v);
	    }
	}
	cout << "cost : " << cost << endl;
	// cout << "Edges : " << MST;
	return cost;
}

