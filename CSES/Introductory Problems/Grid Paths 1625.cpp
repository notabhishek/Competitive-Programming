// Problem: Grid Paths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1625
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
 
#define trace(...) cout <<"L:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
 
const ll INF = LLONG_MAX;
const int MOD = 1e9 + 7;
 
ll fpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }
 
 
string s;
bool vis[7][7];
int tovisit;
int ans;
 
void dfs(int r, int c, int i) { 
	// trace(r, c, i);
	vis[r][c] = 1;
	tovisit--;
	if(i == s.length()) {
		// cout << tovisit <<  " " << r << ' ' << c << endl;
		if(r== 6 && c == 0)
		ans += tovisit == 0;
		tovisit ++;
		vis[r][c] = 0;
		return;
	}
	if(r==6 && c == 0) {
		vis[r][c] = 0;
		tovisit++;
		return;
	}
	switch(s[i]) {
		case 'L' : if(c > 0 && vis[r][c-1]==0) dfs(r, c-1, i+1); break;
		case 'R' : if(c < 6 && vis[r][c+1]==0) dfs(r, c+1, i+1); break;
		case 'U' : if(r > 0 && vis[r-1][c]==0) dfs(r-1, c, i+1); break;
		case 'D' : if(r < 6 && vis[r+1][c]==0) dfs(r+1, c, i+1); break;
		case '?' : {
			if((r==0 || vis[r-1][c]) && (r==6 || vis[r+1][c])) 
				if((c>0 && !vis[r][c-1]) && c<6 && !vis[r][c+1]) {
					vis[r][c] = 0; tovisit++;
					return;
				}
				
			if((c==0 || vis[r][c-1]) && (c==6 || vis[r][c+1]))
				if((r>0 && !vis[r-1][c] ) && (r<6 && !vis[r+1][c])){
					vis[r][c] = 0; tovisit++;
					return;
				}
				
			if(c > 0 && vis[r][c-1]==0) dfs(r, c-1, i+1);
			if(c < 6 && vis[r][c+1]==0) dfs(r, c+1, i+1);
			if(r > 0 && vis[r-1][c]==0) dfs(r-1, c, i+1);
			if(r < 6 && vis[r+1][c]==0) dfs(r+1, c, i+1);
		}
	}
	tovisit++;
	vis[r][c] = 0;
}
void solve()
{
	cin >> s;
	tovisit = 49;
	dfs(0, 0, 0);
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
