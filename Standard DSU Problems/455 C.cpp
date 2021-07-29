// Problem: C. Civilization
// Contest: Codeforces - Codeforces Round #260 (Div. 1)
// URL: https://codeforces.com/problemset/problem/455/C
// Memory Limit: 256 MB
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

const ll INF = LONG_LONG_MAX;
const int MOD = 1e9 + 7;

ll fpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

const int NAX = 3e5 + 100;
int par[NAX];
int siz[NAX];
 
void init(int n) {
	for(int i = 1; i <= n; ++i) {
		par[i] = i;
		siz[i] = 1; 
	}
}

int getp(int u) {
	if(par[u] == u)
		return par[u];
	return par[u] = getp(par[u]);
}

void uni(int x ,int y) {
	int u = getp(x);
	int v = getp(y);
	if(u == v)
		return;
	if(siz[u] > siz[v])
		swap(u , v);
	siz[v] += siz[u];
	par[u] = v;
}

vector<vector<int>> g;
vector<bool> vis;
vector<int> dia;

int d, far;
int root;
void dfs(int u , int p, int depth) {
	vis[u] = 1;
	uni(u, root);
	if(depth > d) {
		d = depth;
		far = u;
	}
	for(auto &v: g[u]) 
		if(v != p) 
			dfs(v, u, depth + 1);
}

void solve()
{
	int n , m , q;
	cin >> n >> m >> q;
	g.resize(n + 1);
	
	for(int i = 0; i < m; ++i) {
		int u , v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	init(n);
	vis.resize(n + 1, 0);
	dia.resize(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			root = i;
			d = 0;
			far = i;
			dfs(i, -1, 0);
			dfs(far, -1, 0);
			
			dia[ getp(i) ] = d;
		}
	}
	
	// for(int i = 1; i <= n; ++i) cout << getp(i) << " "; cout<<endl;
	
	while(q--) {
		int qt;
		cin >> qt;
		if(qt == 1) {
			int u;
			cin >> u;
			cout << dia[ getp(u) ] << "\n";
		} else {
			int u , v;
			cin >> u >> v;
			
			int pu = getp(u) , pv = getp(v);
			if(pu == pv) {
				
			} else {
				int newd = 1 + ((dia[pu]+1)/2) + ((dia[pv] + 1)/2);
				newd = max(newd , max(dia[pu] , dia[pv]));
				
				uni(u , v);
				int newp = getp(u);
				dia[newp] = newd;
			}
		}
	}
	
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