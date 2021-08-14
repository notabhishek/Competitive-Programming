# CodeNation 

### 1. Yet another string operation problem
- Given two strings A, B( |A| = |B| <= 1000), you can do 2 types of operations
- 1. set A[i]=B[i], cost = 1
- 2. reverse A[i...j],cost = C(given), this operation can be performed only once
- Find the min cost to make A = B
```
Sample Input 1:
abceda
bdecbo
1
Sample Output 1:
3

Sample Input 2:
finger 
ginger
0
Sample Output 2:
1
```
##### Logic: 
- precalculate dp[i][j] = count of k such that i<=k<=j and a[k]!=b[k] after a[i...j] is reversed
```
void solve()
{
	string a, b;
	int c;
	cin >> a >> b >> c;
	
	int n = a.length();
	int tot = 0;
	for(int i = 0; i < n; ++i) tot += a[i] != b[i];
	int dp[n][n]; // dp[i][j] = count of k such that i<=k<=j and a[k]!=b[k] after a[i...j] is reversed
	memset(dp, 0, sizeof dp);
	
	for(int len = 1; len <= n; ++len)
		for(int i = 0; i + len-1 < n; ++i) {
			int j = i + len-1;
			if(len == 1) 
				dp[i][j] = (a[i] != b[i]);
			else if(len == 2) 
				dp[i][j] = (a[i] != b[j]) + (a[j] != b[i]);
			else
				dp[i][j] = (a[i] != b[j]) + (a[j] != b[i]) + dp[i+1][j-1]; 
		}
		
	int ans = tot;
	for(int i = 0; i < n; ++i) {
		int diff = 0;
		for(int j = i; j < n; ++j) {
			diff += a[j]!=b[j];
			int cur = tot - diff + dp[i][j] + c;
			ans = min(ans, cur);
		}
	}
	cout << ans << "\n";
}
```

### 1. Mex in subtree ( Non Distinct values )
- Given a tree, and values for nodes, not necessarily distinct ( N<=1e5, val[i] <= 1e9)
- Find MEX of subtree for each node
- Not related to problem: The same problem was asked in another hiring round by CN, the only difference being val[i] were distinct, below approach works on both the problems but a much simpler solution to that problem is [here](https://github.com/notabhishek/Competitive-Programming/blob/main/Hiring%20Round%20Problems/Codenation_oncampus.md) 
```
Sample Input 1:
6
3 0 6 0 5 4 
6 4 
3 5 
1 3 
2 6 
6 1 
Sample Output 1:
1 1 0 1 0 1 

Sample Input 2:
5
7 0 8 5 4 
2 4 
5 2 
4 3 
5 1 
Sample Output 2:
1 1 0 0 1
```
##### Logic: 
- We use DSU on trees / Small to Large merging [Reference](https://codeforces.com/blog/entry/44351) 
- For finding MEX, you can maintain set/ordered set of subtree and then binary search. Complexity: nlog^3 n , most probably TLE
- Use segtree and seg descend to find MEX in log(n). Complexity: nlog^2 n 
```
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> val;

// segment tree to find mex in logn starts here
const int MAXN = 1e5 + 1;
int t[ 4 * MAXN ];
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void upd(int pos, int new_val) {
	update(1, 0, n-1, pos, new_val);
}

// find mex using seg descend O(logn)
int mex(int v, int tl, int tr) {
	if(tl == tr) return tl;
	int tm = (tl + tr)/2;
	if(t[2*v] == (tm-tl + 1)) 
		return mex(2*v+1, tm+1, tr);
	return mex(2*v, tl, tm);
}

// small to large merging starts here
const int maxn = 3e5 + 10;
int sz[maxn];
bool big[maxn];
int cnt[maxn]; // stores the frequency of val[u] in current subtree 
int res[maxn];
void dfs_size(int v, int p) {
	sz[v] = 1;
	for (auto u : g[v]) {
		if (u != p) {
			dfs_size(u, v);
			sz[v] += sz[u];
		}
	}
}

void add(int v, int p, int x){
   	if(val[v] <= n) {
   		cnt[val[v]] += x;
   		if(x == 1 && cnt[val[v]] == 1) // just set for first time
   			upd(val[v], x);
   		if(x == -1 && cnt[val[v]] == 0) // only erase if cnt = 0
   			upd(val[v], x);
   	}
   	
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x);
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // clear small children from subtree
    
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from tree
    add(v, p, 1);
    
    //now tree has all values in subtree of v
    res[v] = mex(1, 0, n-1);
    
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}

void solve()
{
	cin >> n;
	val.resize(n);
	g.resize(n);
	for(auto &i : val) cin >> i;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs_size(0, -1);
	dfs(0, -1, 1);
	for(int i = 0; i < n; ++i) cout << res[i] << " ";
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
```

