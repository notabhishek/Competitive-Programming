# CodeNation


## 1. Homecoming Party
- Given an array A, for each index i find count of j, s.t. a[i]%a[j] = 0 or a[j]%a[i] = 0 , i!=j
- Logic: Sieve
```
Sample Input:
5
2 3 4 5 6
Sample Output:
2 1 1 0 2 
```
```
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	const int NAX = 1e5 + 100;
	vector<int> cnt( NAX + 1 , 0);
	vector<int> f(NAX + 1, 0);
	for(auto &i : a) f[i]++;
	for(int i = 1; i < NAX; ++i) {
		if(f[i] != 0)
		for(int j = i; j < NAX; j+=i) {
			cnt[i]+= f[j]; 
			cnt[j]+= f[i];
		}
	}
	for(auto &i : a) 
		cout << cnt[i] - f[i] - 1<< " ";
	cout << "\n";
}
```
## 2. Alternating Queries
- Given 2 types of queries on an array
- 1 idx val, set a[idx] = val
- 2 l r,  return max value of  a[i]-a[i+1]+...  for every subarray [i, ]  in [l,r] 
- Logic: Segment Tree
```
Sample Input:
5
1 -2 3 4 5 
3
2 1 5 
1 4 -1
2 1 5
Sample Output:
7
12
```
```
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
struct node {
	// pn : starts at positive and ends with negative sign
	// [0 = max sum subarray ] [ 1= max prefix ] [ 2= max suffix ]
	vector<int> pp;
	vector<int> nn;
	vector<int> pn;
	vector<int> np;
	int sum;
	int len;
	node() {
		len = sum = 0;
		pp.resize(3,0);
		nn.resize(3,0);
		pn.resize(3,0);
		np.resize(3,0);
	}
	void operator = (const node &a) {
        pp = a.pp;
        nn = a.nn;
        pn = a.pn;
        np = a.np;
        len = a.len;
        sum = a.sum;
    }
};
const int MAXN = 3e5 + 5;
node OUT_OF_RANGE;

int n , q;
int a[MAXN];
node tree[4*MAXN];

void merge(node &cur , node l , node r) {
	if(l.len == 0) {
		cur = r;
		return;
	} 
	if(r.len == 0) {
		cur = l;
		return;
	}
	cur.sum = l.sum + r.sum;
	cur.len = l.len + r.len;
	cur.pp[0] = max(l.pp[0], r.pp[0]);
	cur.pp[0] = max(cur.pp[0], max(l.pp[2] + r.np[1] , l.pn[2] + r.pn[1]));
	
	cur.pn[0] = max(l.pn[0], r.pn[0]);
	cur.pn[0] = max(cur.pn[0], max(l.pp[2] + r.nn[1] , l.pn[2] + r.pn[1]));
	
	cur.np[0] = max(l.np[0], r.np[0]);
	cur.np[0] = max(cur.np[0], max(l.np[2] + r.np[1] , l.nn[2] + r.pp[1]));
	
	cur.nn[0] = max(l.nn[0], r.nn[0]);
	cur.nn[0] = max(cur.nn[0], max(l.nn[2] + r.pn[1] , l.np[2] + r.nn[1]));
	
	cur.pp[1] = max(l.pp[1], l.sum + (l.len%2 ? r.np[1] : r.pp[1]));
	cur.pn[1] = max(l.pn[1], l.sum + (l.len%2 ? r.nn[1] : r.pn[1]));
	cur.np[1] = max(l.np[1], -l.sum + (l.len%2 ? r.pp[1] : r.np[1]));
	cur.nn[1] = max(l.nn[1], -l.sum + (l.len%2 ? r.pn[1] : r.nn[1]));

	cur.pp[2] = max(r.pp[2], r.len%2 ? l.pn[2] + r.sum : l.pp[2] - r.sum);
	cur.pn[2] = max(r.pn[2], r.len%2 ? l.pp[2] - r.sum : l.pn[2] + r.sum);
	cur.np[2] = max(r.np[2], r.len%2 ? l.nn[2] + r.sum : l.np[2] - r.sum);
	cur.nn[2] = max(r.nn[2], r.len%2 ? l.np[2] - r.sum : l.pn[2] + r.sum);
}

void build(int v , int tl, int tr) {
	if(tl == tr) {
		int val1 = a[tl]; // max((int)0, a[tl]);
		int val2 = -a[tl]; // max((int)0, -a[tl]);
		tree[v].pp = {val1, val1, val1};
		tree[v].nn = {val2, val2, val2};
		tree[v].pn = {0, 0, 0};
		tree[v].np = {0, 0, 0};
		tree[v].sum = a[tl];
		tree[v].len = 1;
	} else {
		int tmid = (tl + tr)/2;
		build(2*v , tl , tmid );
		build(2*v + 1 , tmid + 1 , tr);
		merge(tree[v] , tree[2*v] , tree[2*v + 1]);
	}
} 
node query(int v , int tl, int tr , int l , int r) {
	if(tl > r || l > tr)
		return OUT_OF_RANGE;
	if(tl >= l && tr<=r) 
		return tree[v];
	int tmid = (tl + tr)/2;
	node cur;
	merge(cur , query(2*v , tl , tmid , l , r) , query(2*v + 1 , tmid + 1 , tr, l , r));
	return cur;
}
void update(int v , int tl , int tr , int idx , int val) {
	if(tl == tr) {
		tree[v].pp = {val, val, val};
		tree[v].nn = {-val, -val,-val};
		tree[v].pn = {0, 0, 0};
		tree[v].np = {0, 0, 0};
		tree[v].sum = val;
		tree[v].len = 1;
	}
	else {
		int tmid = (tl + tr)/2;
		if(idx > tmid)
			update(2*v+1 , tmid + 1 , tr , idx , val );
		else 
			update(2*v , tl, tmid, idx , val);
		merge(tree[v] , tree[2*v] , tree[2*v + 1]);
	}
}
int query(int l , int r) {
	node cur = query(1, 0 , n-1 , 0 , n-1);
	return max(cur.pp[0] , cur.pn[0]);
}
void update(int i , int j) {
	update(1 ,0 , n-1 , i , j);
}
void print() {
	for(int i = 0; i < n; ++i) {
		cout << query(1, 0 , n-1, i, i).pp[0] << " ";
	}
	cout << endl;
}
int32_t main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	build(1 , 0 , n-1);
	cin >> q;
	while(q--) {
		// print();
		int t , l , r;
		cin >> t >> l >> r;
		if(t == 1) {
			--l;
			update(l, r);
		} else {
			--l; --r;
			cout << query(l , r) << "\n";
		}
	}
	return 0;
}
```
# 3. Find MEX in tree
- Given a tree with 10000 nodes , root 0 for each node find mex of its subtree i.e smallest value not present in subtree
- All nodes have distinct values,  0<= val_i < n
- Logic: 
- For every node which is not an ancestor of value ZERO, mex = 0
- For ancestors of ZERO calculate mex linearly using set
```
Sample Input:
6
0 1 
1 2 
0 3
3 4 
3 5
4 3 5 1 0 2
Sample Output:
6 0 0 3 1 0 
```
```
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> val;
vector<int> par;
vector<int> in;
vector<int> out;
vector<int> mex;
int Time;
int zero; // pos of value 0
void dfs(int u, int p) {
	in[u] = ++Time;
	par[u] = p;
	for(auto &v : g[u])
		if(v!=p)
			dfs(v, u);
	out[u] = ++Time;  
}
// u is ancestor of v?
bool isAnc(int u, int v) {
	return in[u] <= in[v] && out[u] >= out[v];
}

set< int > s;
void calc(int u) {
	for(auto &v: g[u] )
		if(v != par[u] && !isAnc(v, zero))
			calc(v);
	s.erase(val[u]);
}
void solve()
{
	cin >> n;
	g = vector<vector<int>>(n);
	for(int i = 1; i < n; ++i) {
		int u , v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	val.resize(n);
	for(auto &i : val) cin >> i;
	zero = find(val.begin(), val.end(), 0) - val.begin();
	
	Time = 0;
	in.resize(n);
	out.resize(n);
	par.resize(n);
	mex.resize(n, n);
	dfs(0, -1);
	
	for(int i = 0; i <= n; ++i) s.insert(i);
	// erase zero's subtree
	for(int i = 0; i < n; ++i) {
		if(isAnc(zero, i)) 
			s.erase(val[i]);
		if(!isAnc(i, zero))
			mex[i] = 0;
	}
	mex[zero] = *s.begin();
	
	int cur = par[zero];
	while(cur != -1) {
		calc(cur);
		mex[cur] = *s.begin();
		cur = par[cur];
	}
	for(auto &i : mex) cout << i << " ";
	
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
```
