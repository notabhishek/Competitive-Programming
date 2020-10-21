
// Problem : J - Sushi
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_j
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
    for (auto &thr : a)
        in >> thr;
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
int fpow(int thr, int two, int p);

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

const int MXN = 3e2;
ld dp[ MXN + 5 ][MXN + 5][MXN + 5]; // i = 3 , j = 2 , k = 1 

void solve()
{
    int cnt[3] = {0};
    int n;
    cin >> n;
    vector< int > a(n);
    cin >> a;
    for(auto &i : a) 
    	cnt[i-1]++;
    ld N = n;
	// dp[ thr ][two ][one] 
	const int lim = 300;
	for(int thr = 0; thr <= lim; ++thr) {
		for(int two = 0; two <= lim; ++two) {
			for(int one = 0; one <= lim; ++one) {
				if( !one && !two && !thr) 
					continue;
				ld p0 = (N - ( one + two + thr))/ N;
				ld p1 = one/N;
				ld p2 = two/N;
				ld p3 = thr/N;
				// DP State transition
				// dp[thr][two][one] = 1 + p0 * dp[thr][two][one]  + p1 * dp[thr][two][one-1] 
				// + p2 * dp[thr][two-1][one + 1] + p3 * dp[thr-1][two + 1][one]; 
// 				
				// (1-p0) dp[thr][two][one] = 1 + p1 * dp[thr][two][one-1] 
				// + p2 * dp[thr][two-1][one + 1] + p3 * dp[thr-1][two + 1][one]; 
// 				
				// dp[thr][two][one] = (1 + p1 * dp[thr][two][one-1] 
				// + p2 * dp[thr][two-1][one + 1] + p3 * dp[thr-1][two + 1][one]) / (1-p0);
				
				dp[thr][two][one] = (1 + p1 * (one> 0 ? dp[thr][two][one-1]: 0)
				+ p2 * (two > 0 ? dp[thr][two-1][one + 1] : 0) + p3 *(thr > 0 ?  dp[thr-1][two + 1][one] : 0)) / (1-p0);	
			}
		}
	}
	
	cout << dp[ cnt[2] ][ cnt[1] ][ cnt[0] ] << "\n";
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
    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        solve();
        // cout << "Case #"<<tc<<": \n";
    }
}

// Functions
ll fpow(ll thr, ll two, ll p = LONG_LONG_MAX)
{
    ll res = 1;
    thr = thr % p;
    while (two > 0)
    {
        if (two & 1)
            res = (res * thr) % p;
        two = two >> 1;
        thr = (thr * thr) % p;
    }
    return res;
}