// flip a[idx] and find idx of kth one (both logn and log^2 n solutions)

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e5 + 1;
int n;
int tree[ 4*MAXN ];
int a[ MAXN ];

void build(int v , int tl , int tr) {
	if(tl == tr) {
		tree[v] = a[tl];
	} else {
		int tmid = (tl + tr)/2;
		build(2*v , tl , tmid);
		build(2*v + 1 , tmid + 1 , tr);
		tree[v] = tree[2*v] + tree[2*v + 1];
	}
} 
int sum(int v , int tl , int tr , int l , int r) {
	if(tr < l || r < tl) {
		return 0;
	}
	
	if(tr <= r && tl >= l) {
		return tree[v];
	}
	int tmid = (tl + tr)/2;
	return sum(2*v , tl , tmid , l , r) + sum(2*v + 1, tmid + 1, tr , l , r);
}

void flip(int v , int tl, int tr , int idx) {
	if(tl == tr) {
		tree[v] = 1 - tree[v];
	} else{
		int tmid = (tl + tr)/2;
		if(idx > tmid) 
			flip(2*v + 1 , tmid + 1 , tr , idx);
		else 
			flip(2*v , tl , tmid , idx);
		tree[v] = tree[2*v] + tree[2*v + 1];
	}
}

int queryKth(int v , int tl , int tr, int k) { // log n solution
	if( k > tree[v] ) { // does not contain K ones
		return -1;
	}
	if(tl == tr)
		return tl;
	int tm = (tl + tr)/2;
	if(tree[ v * 2] >= k)
		return queryKth(2*v , tl , tm , k);
	else 
		return queryKth(2*v + 1, tm + 1 , tr , k - tree[2*v]);
}


int bs(int k) { // log^2 n solution
	int lo = 0, hi = n-1;
	int ans = hi;
	while( lo <= hi ) {
		int mid = (lo + hi)/2;
		if(sum(1 , 0 , n-1 , 0 , mid) < k) {
			lo = mid + 1;
		} else {
			ans = mid;
			hi = mid-1;
		}
	}
	return ans;
}
int32_t main() {
	
	int m;
	cin >> n >> m;
	for(int i = 0 ; i < n; ++i) 
		cin >> a[i];
	build(1 , 0 , n-1);
	while( m-- ) {
		int q , l;
		cin >> q >> l;
		if( q == 1) {
			flip(1 , 0 , n-1, l);
		} else {
			// cout << bs(l+1) << "\n";
			cout << queryKth(1 , 0 , n-1 , l + 1) << "\n";
		}
	}
}