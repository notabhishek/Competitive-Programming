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
 
vector<string> a(8);
bool chk(int r , int c) {
	// same col
	for(int i = r-1; i >=0 ; --i) if(a[i][c] == 'Q') return false;
	//left diag
	int i = r-1 , j = c-1;
	for(; i>=0 && j>=0;) {
		if(a[i][j] == 'Q') return false;
		--i; --j;
	}
	i = r-1;
	j = c+1;
	for(; i>=0 && j<8;) {
		if(a[i][j] == 'Q') return false;
		--i; ++j;
	}
	return true;
}
int solve(int r) {
	if(r == 8 ) {
		return 1;
	}
	int ans = 0;
	for(int c  = 0 ; c < 8; ++c) {
		if(a[r][c] == '.' && chk(r , c) ) {
			a[r][c] = 'Q';
			ans+=solve(r+1);
			a[r][c] = '.';
		}
	}
	return ans;
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
    
    for(auto &i : a) cin >> i;
    
    cout << solve(0) << endl;
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
