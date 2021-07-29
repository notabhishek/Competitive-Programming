# MindTickle

## Offer 
```
MindTickle Campus Hiring 6-months+FTE

Eligibility Criteria
Course - B. Tech
Branch - CSE, ECE
Graduation Year- 2022
CGPA- 7 and above

Job Designation - Software Development Engineer

Tentative Date of Joining - June, 2022
Place of Posting - Pune
Bond - None
Internship Stipend(for 6 months) - Rs. 35,000 pm
CTC -  32,50,000 
{ 17,50,000 base + Joining Bonus: 1,00,000 + Retention Bonus: 7,00,000 (2.8 lakhs after completion of 1st year and 4.2 lakhs after completion of 2nd year) + 7 Lakh worth of ESOP's which will be converted into units and shared}
```
## Total time - 90 mins
## Problems

### 1. Stay Healthy
Given N ( 0 < N < 1e15 ), allowed jump sizes [1, 2, 4]. Find minimum jumps to make N
```
Sample Input:
10
Sample Output:
3
```
#### Logic: Greedy
- Taking 4 is always optimal
```
int jumps(long long n) {
  long long ans = n/4;
  n%=4;
  if(n == 2 || n == 1) ++ans;
  if(n == 3) ans += 2;
  return ans;
}
```

### 2. Ticklersion Dilemma
Given an array A ( size <= 1e5 , -1e6<= A[i] <= 1e6) of integers, you are allowed to flip sign of atmost 2 subarrays, what is the maximum subarray sum
```
Sample Input:
8
2 -19 -1 3 -39 -1 5 -2
Sample Output:
70
```
#### Logic: DP
- Dp[ prefix_i ][ sign_of_i ][ flipped_subarrays ] = max sum
```
int solve(int n, vector<int> a, int k) {
	// dp[ prefix ][ sign of i ][ total flipped subarrays ] 
	int dp[n+1][2][k + 1];
	
	int ans = 0;
	for(int sub = 0; sub <= k; ++sub) {
		dp[0][0][sub] = dp[0][1][sub] = 0;
		for(int i = 1; i <= n; ++i) {
			dp[i][0][sub] = a[i-1]+max(dp[i-1][0][sub], dp[i-1][1][sub]);
			if(dp[i][0][sub] < 0)
				dp[i][0][sub] = 0;
			
			if(sub > 0)
				dp[i][1][sub] = -a[i-1]+max(dp[i-1][0][sub-1], dp[i-1][1][sub]);
			else 
				dp[i][1][sub] = 0;
			
			if(dp[i][1][sub] < 0)
				dp[i][1][sub] = 0;
			
			ans = max(ans, max(dp[i][0][sub], dp[i][1][sub]) );
		}
	}
	return ans;
}
```
### 3.El Professor and his surprise test
- Given a tree rooted at 0 ( N = 1e5 )
- initially 0 knows answers to test, at 1 sec 0 tells answers to any child of 0 (say C1) 
- in the next second 0 tells the answer to another child of 0(say C2) and C1 also tells answers to some child of c1(say C11) 
- and this goes on until everyone knows the answers, what is the time required
```
Sample Input: 
7
0 1 
0 2
1 3 
1 4
2 5
3 6

Sample Output: 
3
```
#### Logic: DFS
```
vector<vector<int>> g;
int dfs(int u , int p) {
	vector<int> c;
	for(auto &v: g[u]) 
		if(v != p) 
			c.push_back(dfs(v , u));
	sort(c.begin() , c.end());
	reverse(c.begin() , c.end());
	int ans = 0;

	for(int i = 0; i < c.size(); ++i) 
		ans = max(ans, i+1 + c[i]);
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	g.resize(n);
	for(int i = 1 ; i < n; ++i) {
		int u , v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = dfs(0, -1);
	cout << ans << "\n";
}
```

### 4. Corona Virus Infection
- Given a graph ( N = 1e5 ) having N-1 bi-directional edges
- every node is either 0, or 1 
- The value of a subgraph is  abs( count(0) - count(1) ) , subgraph has to be connected
- find maximum value of any subgraph, and print nodes in the subgraph
```
Sample Input:
8
1 0 0 1 1 0 0 0 
7 1 
3 5
1 6 
4 3
6 3 
2 3 
7 8 

Sample Output:
4
6
1 2 3 6 7 8 
```
#### Logic: DP
- (assuming whole graph is a connected tree) 
- Find down[u] = max sum in subtree of u, taking u
- Fin up[u] = max sum in tree except subtree of u, taking u
- Max sum subgraph having u = up[u] + down[u]
- Perform this 2 times 1 for getting max cnt(1)-cnt(0), other for getting max cnt(0)-cnt(1)
- Perform dfs to get path
```
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
```

