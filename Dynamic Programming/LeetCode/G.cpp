
// Problem : G. Reducing Delivery Cost
// Contest : Codeforces - Codeforces Round #677 (Div. 3)
// URL : https://codeforces.com/contest/1433/problem/G
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b)
{
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

const int R4[4] = {-1, 0, 1, 0}, C4[4] = {0, 1, 0, -1};
const int R8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, C8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const ll INF = 1e9;
const int MOD = 1e9 + 7;

const int MXN = 1e3 + 1 , MXM = 1e3+1;
vector< pair<int , int> > adj[MXN];
int N , M , K;

vector< ll > dijkstra(int s) {
	vector <ll> d( N + 1 , INF );
	set < pair < int , int > > pq; // wt , node
	d[s] = 0;
	pq.insert({ d[s] , s});
	while(pq.size() != 0) {
		int v = pq.begin() -> ss;
		pq.erase(pq.begin());
		for(auto [to , w] : adj[v] ) {
			if(d[to] > d[v] + w) {
				auto it = pq.find({d[to] , to});
				if( it != pq.end() )
					pq.erase(it);
				d[to] = d[v] + w;
				pq.insert({d[to] , to});
			}
		}
	}
	return d;  
}
void solve()
{
    cin >> N >> M >> K;
    
	for(int i = 0; i < M; ++i) {
		int u , v , w;
		cin >> u >> v >> w;	
		adj[u].pb({v, w});
		adj[v].pb({u , w});
	}
	
	vector<ll> d[N + 1];
	memset(d , INF , sizeof d);
	for(int i = 1; i <= N; ++i) {
		d[i] = dijkstra(i);
	}
	
	int ans = INF;
	vector< pair< int , int >> b(K);
	for(auto &i : b) 
		cin >> i.ff >> i.ss;
	for(int i = 1; i <= N; ++i) {
		for(auto [j , w] : adj[i] ) {
			// wt of (i , j)  is now 0
			int cans = 0;
			for(auto [x ,y] : b) {
				cans += min({ d[x][y] , d[x][i] + d[j][y] , d[x][j] + d[i][y] });
			}
			ans = min(ans , cans);
		}
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