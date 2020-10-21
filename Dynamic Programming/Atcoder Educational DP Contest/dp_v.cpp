
// Problem : V - Subtree
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_v
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Code by : Abhishek Tiwari @devil_within
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
const long double PI = acos(-1);
using namespace std;

using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long int;
using ld = long double;
// using int = int64_t;

/*******************************************************************************************/
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i)
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
int fpow(int x, int y, int p);

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b)
{
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const ll INF = LONG_LONG_MAX;
const int MAXN = 2e5, MAXM = 2e5;
const int MOD = 1e9 + 7;

const int MXN = 1e5 + 5;
int n, m;
vector<int> adj[MXN];
ar<ll, 2> down[MXN], up[MXN]; // Black , White
vector<ar<ll, 2>> pre[MXN]; 
vector<ar<ll, 2>> suf[MXN];

ll mul(ll a, ll b)
{
    a %= m;
    b %= m;
    return (a * b) % m;
}
ll add(ll a, ll b)
{
    a %= m;
    b %= m;
    return (a + b) % m;
}
ar<ll, 2> mul(ar<ll, 2> &a, ar<ll, 2> &b)
{
    ar<ll, 2> c = {mul(a[0], b[0]), mul(a[1], b[1])};
    return c;
}

void print(ar<ll, 2> &a) {
	cout << pair < int , int > ({a[0] , a[1]}) << ",";	
}

// Number of ways to colour subtree of current node
		// parent
// 		  / 	\      \        \
	// child1 child2 s child4 child5
	// up[s] = ways to colour (tree - s's subtree)
	// = up[parent] * down[child1] * down[child2] *  down[child4] * down[child5]
void cdown(int s, int p)
{
    down[s] = {1, 1};
    pre[s].pb({1, 1});
    for (auto &i : adj[s])
        if (i != p)
        {
            cdown(i, s);
            down[s][0] = mul(down[s][0], add(down[i][0], down[i][1]));
            down[s][1] = mul(down[s][1], down[i][1]);
            // Prefix and  suffix for knowing multiplication fast
            // Could have used inverse mod if m was prime ie.  (prod of all children) / curr
            pre[s].pb({ add(down[i][0] , down[i][1] ) , down[i][1]});
            suf[s].pb({ add(down[i][0], down[i][1]) ,  down[i][1]});
        }
    suf[s].pb({1, 1});
    for (int i = 1; i < pre[s].size(); ++i)
        pre[s][i] = mul(pre[s][i], pre[s][i - 1]);
    for (int i = suf[s].size() - 2; i >= 0; --i)
        suf[s][i] = mul(suf[s][i], suf[s][i + 1]);
}


// Number of ways to colour (tree - subtree)
void cup(int s, int p)
{
    int idx = 1;
    for (auto &i : adj[s])
    {
        if (i != p)
        {
            up[i] = {up[s][0], up[s][1]};
            assert(idx-1 >=0 && idx-1 < pre[s].size() );
            up[i] = mul(up[i], pre[s][idx - 1]);
            assert(idx-1 >=0 && idx < suf[s].size() );
            up[i] = mul(up[i], suf[s][idx]);
            up[i][0] = add(up[i][0] , 1);
            cup(i, s);
            ++idx;
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cdown(1, -1);
    up[1] = {1, 1};
    cup(1, -1);
    for (int i = 1; i <= n; ++i)
        cout << mul(up[i][0], down[i][0]) << "\n";
}

signed main()
{
#ifndef ONLINE_JUDGE
// freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" ,
// stdout);freopen("error.txt" , "w" , stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        solve();
        // cout << "Case #"<<tc<<": \n";
    }
}

// Functions
ll fpow(ll x, ll y, ll p = LONG_LONG_MAX)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}