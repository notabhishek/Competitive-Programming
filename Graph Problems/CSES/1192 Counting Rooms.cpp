// Problem : Counting Rooms
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1192
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
//Code by : Abhishek Tiwari
//@devil_within
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define repr(i,a,b) for(int i=(a);i>(b);--i)
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second 
#define gcd __gcd
#define lcm(a,b) ((a)*(b))/gcd(a,b)
#define VI vector<int>
#define VVI vector<vector<int>>
#define VII vector<pair<int,int>>,
#define lli long long 
#define int int64_t
#define pii pair<int,int> 
const int mod = 1000000007;
const lli inf = 1e15; //1e15
const double PI = 3.141592653589793;
using namespace std;
 
/*******************************************************************************************/
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
template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }
/*******************************************************************************************/
/*******************************************************************************************/
int fpow(int x, int y, int p); 
 
int n , m;
void dfs(int r , int c , vector<string> &v , vector<vector<bool> > &vis){
	vis[r][c] = true;
	if(r > 0 && v[r-1][c]=='.' && !vis[r-1][c])
		dfs(r-1 , c , v , vis);
	if(r < n-1 && v[r+1][c]=='.' && !vis[r+1][c])
		dfs(r+1 , c , v , vis);
	
	if(c > 0 && v[r][c-1]=='.' && !vis[r][c-1])
		dfs(r , c-1 , v , vis);
	if(c < m-1 && v[r ][c + 1]=='.' && !vis[r][c+1])
		dfs(r  , c+1 , v , vis);
}
int32_t main()  
{
#ifndef ONLINE_JUDGE
//freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" , stdout);freopen("error.txt" , "w" , stderr);
#endif
fio;
//cout << fixed << setprecision(12);
int T = 1;
//cin >> T;
for(int tc = 1 ; tc <= T; ++tc )
{
 
    cin >> n >> m;
    vector<string> v(n);
    for(auto &i: v) cin >> i;
    vector<vector<bool>> vis(n ,  vector<bool > (m , false));
    int c = 0;
    for(int i= 0 ; i < n;++i )
		for(int j = 0 ; j<m;++j) {
			if(v[i][j] == '.' && !vis[i][j]) {
				dfs(i , j , v , vis);
				++c;
				}
		}
	cout << c << endl;
    
    //cout<< "Case #" << tc <<": ";
}
return 0;
}
 
 
 
//Functions 
 
int fpow(int x, int y, int p) { 
    int res = 1; 
   x = x % p;  
   while (y > 0) { 
     if (y & 1) 
        res = (res * x) % p; 
     y = y >> 1; 
        x = (x * x) % p; 
    } 
    return res; 
} 
