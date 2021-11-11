// Problem: Encoding
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/ENCODING
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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

const int MX_LEN = 1e5 + 10;
pair<int,int> dp[MX_LEN][2][10]; // {ans, count}
int p10[MX_LEN];
pair<int,int> rec(string &R, int n, bool tight, int pdig) {
	if(n == 0) return {0, 1};
	pair<int,int> &ret = dp[n][tight][pdig];
	if(ret.first != -1) 
		return ret;
	int ub = tight ? R[R.length()-n]-'0' : 9;
	ll answer = 0;
	ll count = 0;
	for(int dig = 0; dig <= ub; ++dig) {
		auto nxt = rec(R, n-1, tight&(dig==ub), dig);
		answer = (answer + nxt.first) % MOD;
		count  = (count  + nxt.second) % MOD;
		if(dig != pdig) {
			ll add = (dig * p10[n-1] % MOD) * nxt.second % MOD;
			answer = (answer + add) % MOD;
		}
	}
	return ret = {answer, count};
}
void initdp(int n, pair<int,int> val) {
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 10; ++k) 
				dp[i][j][k] = val;
		}
	}
}
void solve()
{
	int nl, nr;
	string L, R;
	cin >> nl >> L >> nr >> R;
	initdp(nr, {-1,-1});
	auto ansR = rec(R, nr, 1, 0);
	initdp(nl, {-1,-1});
	auto  ansL = rec(L, nl, 1, 0);
	ll answer = (ansR.first-ansL.first + MOD) % MOD;
	
	// cout << ansR << " " << ansL << "  " <<answer << "\n";
	//add L 
	for(int i = 0; i < nl; ++i) {
		answer = (answer + (L[i]-'0') * p10[nl-1-i] % MOD)%MOD;
		while(i+1 < nl && L[i+1] == L[i]) ++i;
	} 
	cout << answer << "\n";
}

signed main()
{
    // freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" ,stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    p10[0] = 1;
    for(int i = 1; i < MX_LEN; ++i)
    	p10[i] = p10[i-1] * 10  % MOD;
    for (int tc = 1; tc <= T; ++tc)
    {
        // cout << "Case #"<<tc<<": \n";
        solve();
    }
}
