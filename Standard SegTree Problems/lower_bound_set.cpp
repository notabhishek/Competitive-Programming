// set[a[idx]] = val and find first idx in [l,r] where a[idx]>=x logn
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
#define ar array
const int mod = 1e9 + 7;
const ll INF = 1e15;
const double PI = acos(-1);
using namespace std;
int fpow(int x,int y,int p); 


const int MAXN = 1e5 + 1;
int n , m;
int a[ MAXN ];
int tree[ 4 * MAXN ];

void build(int v , int tl , int tr ) {
	if(tl == tr)
		tree[v] = a[tl];
	else {
		int tmid = (tl + tr)/2;
		build(2*v , tl , tmid);
		build(2*v + 1 , tmid + 1 , tr);
		tree[v] = max(tree[2*v] , tree[2*v + 1]);
	}
}
void update(int v ,  int tl , int tr , int idx , int val) {
	if(tl == tr)
		tree[v] = val;
	else {
		int tmid = (tl + tr)/2;
		if(idx > tmid) 
			update(2*v + 1,  tmid+1 , tr , idx , val);
		else 
			update(2*v , tl , tmid , idx , val);
		tree[v] = max(tree[2*v] , tree[2*v + 1]);
	}  
}
// returns maxValue , index
int combine(int a,int b, int l , int r) {
	if( (a >= l && a <= r)) {
		return a;
	}
	return b;
}
int queryLR(int v , int tl, int tr, int l , int r, int x) { // logn 
	if(l > tr || tl > r) {
		return -1;
	}
	if(tree[v] < x)
		return -1;
	if(tl == tr ) {
		if(tree[v] >= x) 
			return tl;
		return -1;
	} 
	if(tl>=l && tr<=r) {
		int tmid = (tl + tr)/2;
		if(tree[2*v] >= x)
			return queryLR(2*v, tl , tmid , l , r , x);
		else 
			return queryLR(2*v + 1 , tmid + 1 , tr , l , r , x);
	} 
	else { // partial overlap
		int tmid = (tl + tr)/2;
		return combine( queryLR(2*v , tl , tmid , l , r , x) , queryLR(2*v + 1, tmid + 1, tr , l , r , x) , l , r );
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
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	build(1 , 0 , n-1);
	while(m--) {
		int q , l , r;
		cin >> q >> l >> r;
		if(q == 1) {
			update(1 , 0 , n-1 , l , r);
		} else {
			cout << queryLR(1 , 0 , n-1 , r , n-1 , l) << "\n";
		}
	}

	//cout << "Case #"<<tc<<": \n";

}
return 0;
}



//Functions 
int fpow(int x, int y, int p) { 
   int res = 1; 
   x = x % p;  
   while (y > 0) { 
     if (y & 1) res = (res * x) % p; 
     	y = y >> 1; 
        x = (x * x) % p; 
    } 
    return res; 
} 

/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<class T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
*/
