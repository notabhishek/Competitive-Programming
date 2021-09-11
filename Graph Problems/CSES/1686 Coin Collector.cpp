// Problem: Coin Collector
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1686
// Memory Limit: 512 MB
// Time Limit: 1000 ms

// Code by : Abhishek Tiwari @devil_within
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define lcm(a, b) ((a) * (b)) / __gcd(a, b)
#define vt vector<int>
#define pii pair<int, int>
#define ar array
using namespace std;

using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
using ll = long long int;
using ld = long double;

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b)
{
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

/*******************************************************************************************/
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T> ostream &operator<<(ostream &os, const set<T> &v);
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &v);
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v);
template <typename T> inline istream &operator>>(istream &in, vector<T> &a);
/*******************************************************************************************/
// N dimensional Vector, Vec<n , int>
template <int D, typename T> struct Vec : public vector<Vec<D - 1, T>>
{
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template <typename... Args> Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...))
    {
    }
};
template <typename T> struct Vec<1, T> : public vector<T>
{
    Vec(int n = 0, const T &val = T()) : vector<T>(n, val)
    {
    }
};
/*******************************************************************************************/
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}

#define trace(...) //cout <<"L:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)

const ll INF = LLONG_MAX;
const int MOD = 1e9 + 7;

ll fpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }


const int MAXN = 1e5 + 1;
vector<int> g[MAXN];
vector<int> tg[MAXN];
int val[MAXN];

vector<int> vis;
vector<int> order;
int comp[MAXN];
int sccs = 0;
vector< vector< int > >  SCC;

// for condensation graph
vector<int> roots;
vector<int> root_nodes;
vector<vector<int>> cg;


void dfsOrder(int src) {
	vis[src] = true;
	for(auto to : g[src] ) {
		if(!vis[to]) {
			dfsOrder(to);
		}
	}
	order.push_back(src);
}

// dfs on transpose
void dfsSCC(int src) {
	vis[src] = true;
	for(auto to : tg[src]) {
		if(!vis[to]) {
			dfsSCC(to);		
		}
	}
	comp[ src ] = sccs;
	SCC[ sccs ].push_back( src );
}
vector<int> dp;
int calc(int u) {
	if(dp[u] != -1) return dp[u];
	dp[u] = val[u];
	for(auto to : cg[u] ) {
		dp[u] = max(dp[u], val[u] + calc(to));
	}
	return dp[u];
}
void kosaraju(int n) {
	order.clear();
	vis.assign(n+1, false);
	roots.assign(n+1, 0);
	root_nodes.clear();
	cg.clear(); cg.resize(n+1);
	
	for(int node = 1 ; node <= n; ++node )
		if(!vis[node]) 
			dfsOrder(node);
	
	SCC.clear();
	sccs = 0;
	
	// find sccs 
	vis.assign(n+1 , false);
	for(int i = 1; i <= n; ++i ) {
		if(!vis[ order[n - i] ])  {
			SCC.push_back(vector<int> ());
			dfsSCC( order[ n - i ]);
			
			int root = SCC[sccs].front(); root_nodes.push_back(root);
			for(auto &x : SCC[sccs]) roots[x]=root;
			
			++sccs;
		}
	}
	
	// construct Condensation graph
	for(int u = 1; u <= n; ++u) {
		if(u != roots[u]) val[roots[u]] += val[u]; // add node values to their roots in cg
		
		for(auto &v: g[u]) {
			if(roots[u] != roots[v]) 
				cg[roots[u]].push_back(roots[v]);
		}
	}
	
	// calc dp using condensation graph
	int ans = 0;
	dp.assign(n + 1, -1);
	for(int i = 1; i <= n; ++i) 
		ans = max(ans, calc(i));
	cout << ans << "\n";
}

void solve()
{
	int n , m ;
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) cin >> val[i];
	
	for(int i = 0 ; i < m; ++i) {
		int u , v;
		cin >> u >> v;
		g[u].push_back(v);
		tg[v].push_back(u);
	}
	
	kosaraju(n);
}

signed main()
{
    // freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" ,stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        // cout << "Case #"<<tc<<": \n";
        solve();
    }
}

// Functions

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (i)
            os << ", ";
        os << v[i];
    }
    os << "]\n";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v)
{
    os << "{";
    for (auto it : v)
    {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "}\n";
    return os;
}
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &v)
{
    os << "{";
    for (auto it : v)
    {
        os << "(" << it.first << " : " << it.second << ")";
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "}\n";
    return os;
}
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v)
{
    os << "(";
    os << v.first << ", " << v.second << ")";
    return os;
}
template <typename T> inline istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
}
