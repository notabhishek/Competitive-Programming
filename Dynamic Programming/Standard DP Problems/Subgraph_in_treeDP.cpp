/*
Given a graph ( N = 1e5 ) having N-1 bi-directional edges
every node is either 0, or 1
The value of a subgraph is abs( count(0) - count(1) ) , subgraph has to be connected
find maximum value of any subgraph, and print nodes in the subgraph
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int INF = 1e9;
vector<vector<int>> g;
int n;
vector<int> a;
vector<int> down; // max in subtree
vector<int> up; // max in everything except subtree
vector<int> par;
// ans[i] = up[i] + down[i]
/*
	 u
   /	\	\ 
 a		b	c
 		\	
 		d
down[u] =  a[u] + sum ( down[children] )
up[u] = up[par[u]] + down[par[u]] - down[c]
*/
int calcDown(int u, int p) {
	if(down[u] != -INF)
		return down[u];
	par[u] = p;
	for(auto &i : g[u]) 
		if(i!=p) calcDown(i, u);
	down[u] = (a[u] ? 1 : -1);
	for(auto &i : g[u]) 
		down[u] += max( down[i], (int)0);
	return down[u];
}
int calcUp(int u, int p) {
	if(up[u] != -INF)
		return up[u];
	up[u] = (p!=-1 ? max((int)0, up[p] + down[p] - max((int)0, down[u])) : 0);
	for(auto &i : g[u])
		if(i != p) calcUp(i, u);
	return up[u];
}
vector<int> path;
void fDPath(int u, int p){
	path.push_back(u);
	for(auto &v: g[u]) 
		if(v!=p && down[v] > 0)
			fDPath(v, u);
}
void fUPath(int u, int c){
	if(u == -1)
		return;
	int upCont = up[u] + down[u] - max((int)0, down[c]);
	if(upCont > 0) {
		path.push_back(u);
	}
	for(auto &i : g[u]) 
		if(i != c && i!=par[u]) 
			fDPath(i , u);
	fUPath(par[u], u);
}
int solve()
{
	down = vector<int>(n+1, -INF);
	up = vector<int>(n+1, -INF);
	calcDown(1, -1);
	calcUp(1, -1);
	int ans = -INF , node = 1;
	for(int i = 1; i <= n; ++i)  {
		if(up[i] + down[i] > ans) {
			ans = up[i]+down[i];
			node = i;
		}
	}
	fDPath(node, par[node]);
	fUPath(par[node], node);
	return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
	g = vector< vector<int>> (n+1);
	a.resize(n+1);
	par.resize(n+1);
	for(int i = 1; i <= n; ++i) cin >> a[i];	
	for(int i = 1; i < n; ++i) {
		int u , v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);	
	}
	
    int ans1 = solve();
    vector<int> path1 = path;
	for(auto &i : a) i= 1-i;
	int ans2 = solve();
    vector<int> path2 = path;
    if(ans2 > ans1) {
    	swap(path1, path2);
    	ans1 = ans2;
    }
    cout << ans1 << "\n";
    set<int> ps(path1.begin(), path1.end());
    cout << ps.size() << "\n";
    for(auto &i : ps) cout << i << " ";
    cout << "\n";
}
