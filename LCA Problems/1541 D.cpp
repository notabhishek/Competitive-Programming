// Problem: D. Tree Array
// Contest: Codeforces - Codeforces Round #728 (Div. 2)
// URL: https://codeforces.com/contest/1541/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

int n, l;
vector<vector<int>>adj;

int tim;
vector<int> in, out;
vector<vector<int>> up;

void dfs(int v, int p)
{
    in[v] = ++tim;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
        
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    out[v] = ++tim;
}

bool isAnc(int u, int v)
{
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v)
{
    if (isAnc(u, v))
        return u;
    if (isAnc(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!isAnc(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void init(int root) {
    in.resize(n + 1);
    out.resize(n + 1);
    tim = 0;
    l = ceil(log2(n+1));
    up.assign(n + 1, vector<int>(l + 1));
    dfs(root, root);
}

// v is ancestor of u
int dist(int u , int v){
	if(u == v)
		return 0;
		
	int d = 0;
	for (int i = l; i >= 0; --i) {
        if (!isAnc(up[u][i] , v)) {
            u = up[u][i];
            d += 1ll<<i;
        }
    }
    return d + 1;
}

Vec<2, int> dp(205, 205, -1);
int mInv2 = fpow(2ll , MOD-2, MOD);

int F(int i , int j) {
	if(i < 0 || j < 0)	
		return 0;
	int &ret = dp[i][j];
	if(ret != -1)
		return ret;
	if(i == 0)
		return ret = 0;
	if(j == 0)
		return ret = 1;
	ret = (F(i,j-1) + F(i-1, j))%MOD;
	ret = (ret * mInv2) % MOD;
	return ret;
}

void solve()
{
	cin >> n;
	adj = vector<vector<int>>(n+1);
	for(int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int ans = 0;
	int x , a, b;
	
	init(1);
	
	for(int root = 1; root<= n; ++root) {
		int cur = 0;
		
		// for lca
		tim = 0;
		dfs(root, root);
		
		for(int i = 1; i <= n; ++i) {
			for(int j=i+1; j <= n; ++j) {
				// add expected number of inversions {j,i}
				x = lca(i,j);
				a = dist(i , x);
				b = dist(j , x);
				
				/*
				2 paths, prob(path1) = prob(path2) = say p
				then let F(a,b) = number of inversions for path length a,b
				
				F(a,b) = p*F(a-1,b) + p*F(a,b-1) + (1-2p)*F(a,b)
				2p F(a,b) = pF(a-1,b) + pF(a,b-1)
				
				F(a,b) = ( F(a-1,b) + F(a,b-1) )/2;
				*/
				cur+= F(a, b);
				cur %= MOD;	
			}
		}
		
		cur = (cur * fpow(n, MOD-2, MOD)) % MOD;
		ans = (ans + cur) %MOD;
	}
	cout << ans << "\n";
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
