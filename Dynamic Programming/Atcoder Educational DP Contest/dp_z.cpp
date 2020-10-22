// Usinf Li Chao Tree 
// Problem : Z - Frog 3
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_z
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Code by : Abhishek Tiwari @devil_within
#include <bits/stdc++.h>
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

const ll INF = 1e17;
const int MAXN = 2e5, MAXM = 2e5;
const int MOD = 1e9 + 7;


struct line{
	ll m , c; // y = mx + c
	ll at(ll x) {
		return m * x + c;
	}
};
const int MXN = 1e6 + 5;
vector< line > tree( 4 * MXN , {0 , INF});

ll query(ll x , int idx=1 , int tl= 0, int tr=MXN-1) {
	ll cur = tree[idx].at(x);
	if(tl == tr) 
		return cur;
	int tmid = (tl + tr)/2;
	if( x >= tmid )
		return min( cur , query(x , 2*idx+1,tmid+1, tr) );
	return min(cur , query(x ,2*idx, tl , tmid));
}
void insert(line newl, int idx=1 , int tl=0, int tr=MXN-1) {
	int tmid = (tl + tr)/2;
	bool L = newl.at(tl) < tree[idx].at(tl);
	bool M = newl.at(tmid) < tree[idx].at(tmid);
	
	if(M) {
		swap(tree[idx] , newl);
	} 
	if(tl == tr) 
		return;
	if( M == L ) {
		// Intersection at right
		insert(newl , 2*idx + 1, tmid + 1, tr);
	} else {
		// Intersection at left
		insert(newl , 2*idx , tl , tmid);
	}
}
void solve()
{
	 ll n , C;
	 cin >> n >> C;
	 ll h[n+1];
	 for(int i = 1; i <= n; ++i) cin >> h[i];
	 
	 // dp[i] = (for 0 <= j < i) 
	 				// min( dp[j] + (hi - hj) ^ 2 + C) 
	 		//= hi^2 + C + min( -2hihj + hj^2 + dp[j])
	 		//= hi^2 + C + min( -2mx + C' )  
	 
	 vector< ll > dp(n + 1 , 0);
	 dp[1] = 0;
	 for(int i = 1; i <= n; ++i) {
	 	// DP[i] = hi^2 + C + min( value of prev lines at x = h[i] )
	 	if( i != 1) {
			dp[i] = h[i] * h[i] + C + query(h[i]);
		}
		
	 	// Insert this new line
	 	line newl;
	 	newl.m = -2 * h[i];
	 	newl.c = h[i] * h[i] + dp[i];
	 	insert(newl);
	 }
	 cout << dp[n] << endl;
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