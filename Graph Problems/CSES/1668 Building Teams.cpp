// Problem : Building Teams
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1668
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
//Code by : Abhishek Tiwari @devil_within
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second 
#define gcd __gcd
#define lcm(a,b) ((a)*(b))/gcd(a,b)
#define VI vector<int>
#define ll long long 
#define int int64_t
#define pii pair<int,int> 
const int mod = 1e9 + 7;
const ll INF = 1e15;
const double PI = acos(-1);
using namespace std;
 
/*******************************************************************************************/
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { 
    os<<"["; for(int i=0;i<v.size(); ++i) {if(i) os<<", "; os<<v[i]; }  
    os<<"]\n"; return os; 
} 
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) { 
    os<<"{"; for(auto it : v) { os<<it; if(it!=*v.rbegin()) os<<", "; } os<<"}\n"; 
    return os; 
}
template <typename T, typename S> ostream& operator<<(ostream& os, const map<T, S>& v) { 
    os<<"{"; for(auto it:v){ os<<"("<<it.first<<" : "<<it.second<<")"; if(it!=*v.rbegin()) os<<", "; } os<<"}\n"; 
    return os; 
}
template <typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& v) { 
    os<<"("; os<<v.first<<", "<< v.second<<")"; 
    return os; 
} 
template <typename T> inline istream &operator>>(istream &in, vector<T> &a) {
    for(auto &x : a) {in >> x;} return in;
}
/*******************************************************************************************/
int fpow(int x,int y,int p); 
const int mxN = 1e5+1;
vector<int> adj[mxN];
vector<int> ans(mxN , -1);
bool poss = true;
void dfs(int s , int c) {
	ans[s] = c;
	for(auto &i : adj[s]) {
		if(ans[i] == -1) {
			dfs( i , 1-c);
		}else if( ans[i] == c) {
			poss = false;
			return;
		}
	}
}
int32_t main()  
{
#ifndef ONLINE_JUDGE
//freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" , stdout);freopen("error.txt" , "w" , stderr);
#endif
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//cout << fixed << setprecision(12);
int T = 1;
//cin >> T;
for(int tc = 1 ; tc <= T; ++tc )
{
	int n , m;
	cin >> n >> m;
	for(int i = 0 ; i < m;++i) {
		int  u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; ++i) {
		if(ans[i] == -1) 
			dfs(i , 1);
	}
	if(poss) {
		for(int i = 1; i <=n;++i) cout <<1+ ans[i] << " ";
	} else 
	cout << "IMPOSSIBLE\n";
 
}
return 0;
}
 
 
 
//Functions 
int fpow(int x, int y, int p) { 
   int res = 1; 
   x = x % p;  
   while (y > 0) { 
     if (y & 1)  res = (res * x) % p; 
     	y = y>>1; 
        x = (x * x) % p; 
    } 
    return res; 
} 
