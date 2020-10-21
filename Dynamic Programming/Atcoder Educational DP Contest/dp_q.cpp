
// Problem : Q - Flowers
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_q
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
// using ld = long double;
// using int = long long ;
#define int int64_t 
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
const int M = 1e9 + 7;

const int MXN = 2e5;


struct node
{
    int sum;
    bool operator == (const node &a) {
        return a.sum == sum;
    }
    void operator = (const node &a) {
        sum = a.sum;
    }
};

struct segTree
{
    
    vector<node> tree;
    vector<bool> clazy;
    vector<int> lazy;
    int n;
    int MAXN;
    
    node OUT_OF_RANGE = { INT_MIN }; // For Range Query Only
    int LAZY_DEFAULT = 0;
    
    void merge(node &cur, node &l, node &r)
    {
        // complete merge here
        if(l == OUT_OF_RANGE ) {
            cur = r;
        } 
        else if(r == OUT_OF_RANGE ) {
            cur = l;
        }
        else {
            cur.sum = max(l.sum , r.sum);
        }
    }

    void propogate(int v, int tl, int tr)
    {
        // complete propogation here
        if (clazy[v] == true)
        {
            if (tl != tr)
            {
                clazy[2 * v] = true;
                clazy[2 * v + 1] = true;
                lazy[2 * v] = lazy[v];
                lazy[2 * v + 1] =  lazy[v];
            }
            
            tree[v].sum = ( lazy[v] );

            clazy[v] = false;
            lazy[v] = LAZY_DEFAULT;
        }
    }
    void Build(int v, int tl, int tr, vector<int> &a)
    {
        if (tl == tr)
        {
            // complete here
            tree[v].sum = a[tl];
        }
        else
        {
            int tmid = (tl + tr) / 2;
            Build(2 * v, tl, tmid, a);
            Build(2 * v + 1, tmid + 1, tr, a);
            merge(tree[v], tree[2 * v], tree[2 * v + 1]);
        }
    }
    void build(vector<int> &a)
    {
        MAXN = a.size() + 1;
        n = a.size();
        tree.resize(4 * MAXN);
        clazy.assign(4 * MAXN, false);
        lazy.assign( 4 * MAXN, LAZY_DEFAULT);
        Build(1, 0, n - 1 , a);
    }

    void build(int nn ,int init_val)
    {
        vector< int > a(nn , init_val );
        build(a);
    }

    void Update(int v, int tl, int tr, int l, int r, int val)
    {
        if(clazy[v])
            propogate(v, tl, tr);
        if (l > tr || tl > r)
        {
            return;
        }
        if (tl >= l && tr <= r)
        {
            clazy[v] = true;
            lazy[v] = val;
            propogate(v , tl , tr);
        }
        else
        {
            int tmid = (tl + tr) / 2;
            Update(2 * v, tl, tmid, l, r, val);
            Update(2 * v + 1, tmid + 1, tr, l, r, val);
            merge(tree[v], tree[2 * v], tree[2 * v + 1]);
        }
    }

    node Query(int v, int tl, int tr, int l, int r)
    {
        if(clazy[v])
            propogate(v, tl, tr);
        if (l > tr || tl > r)
        {
            // return value out of range
            return OUT_OF_RANGE;
        }
        if (tl >= l && tr <= r)
        {
            return tree[v];
        }
        else
        {
            int tmid = (tl + tr) / 2;
            node cur;
            node left = Query(2 * v, tl, tmid, l, r);
            node right = Query(2 * v + 1, tmid + 1, tr, l, r);
            merge(cur , left , right);
            return cur;
        }
    }
    void pUpdate(int v, int tl, int tr, int idx , int val) {
        if(clazy[v])
            propogate(v , tl , tr);
        if(tl == tr) {
            clazy[v] = true;
            lazy[v] = val;
            propogate(v , tl ,  tr);
            return;
        }
        int tmid = (tl + tr)/2;
        if( idx > tmid )
            pUpdate(2*v + 1 , tmid + 1 , tr , idx , val);
        else 
            pUpdate(2*v ,tl ,tmid ,idx , val);
        merge(tree[v] , tree[2*v] , tree[2*v + 1]);
    }
    
       node pQuery(int v, int tl, int tr , int idx) {
        if(clazy[v])
            propogate(v , tl , tr);
        if(tl == tr)
            return tree[v];
        int tmid = (tl + tr)/2;
        if(idx > tmid ) 
            return pQuery(2*v + 1 , tmid + 1, tr , idx); 
        else 
            return pQuery(2*v , tl , tmid , idx);
    }
    
    void update(int l, int r, int v)
    {
        Update(1, 0, n - 1, l, r, v);
    }
    void update(int idx , int val) {
        pUpdate(1 , 0 , n-1 , idx , val);
    }
    node query(int l, int r)
    {
        return Query(1, 0, n - 1, l, r);
    }
    node query(int idx) {
        return pQuery(1 , 0 , n-1 , idx);
    }
};


void solve()
{
    int N;
    cin >> N;
    vector< ll > h(N) , a(N);
    cin >> h >> a;
	
	segTree tree;
	tree.build(N + 5 , 0);
	vector< ll> dp(N+1 , 0);
	ll ans = 0;
	for( int i = 0; i < N; ++i) {
		dp[ h[i] ] = a[i] + tree.query(0 , h[i]-1).sum;
		ans = max(ans , dp[h[i]]);
		tree.update(h[i] , dp[h[i]] );
	}
	cout << ans << "\n";
	// cout << dp;
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