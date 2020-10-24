// set a[i] = v and find first a[index] >= x // both log^n and logn solutions
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
int tree[ 4 * MAXN];
int a[MAXN];
int n , m;

void build(int v , int tl , int tr) {
	if(tl == tr) {
		tree[v] = a[tl];
	} else {
		int tmid = (tl + tr)/2;
		build(2*v , tl , tmid);
		build(2*v + 1 , tmid +1 , tr);
		tree[v] = max(tree[2*v] , tree[2*v+ 1]);
	}
}

void update(int v , int tl, int tr, int idx , int val) {
	if(tl == tr) {
		tree[v] = val;
	} else {
		int tmid = (tl + tr)/2;
		if(idx > tmid ) 
			update(2*v +1 , tmid + 1 , tr , idx , val);
		else 
			update(2*v , tl , tmid, idx , val);
		tree[v] = max(tree[2*v] , tree[2*v + 1]);
	}
}

int rquery(int v , int tl , int tr , int l , int r) {
	if(l > tr || tl > r)
		return INT_MIN;
	if(tl>=l && tr<=r) 
		return tree[v];
	int tmid = (tl + tr)/2;
	return max(rquery(2*v , tl , tmid , l , r) , rquery(2*v + 1 , tmid+1 , tr , l , r));
}
int bs(int x) { // log ^ n solution
	int lo = 0 , hi = n-1;
	int ans = n;
	while( lo <= hi) {
		int mid = (lo + hi)/2;
		if(rquery(1 , 0 , n-1 , 0 , mid) < x){
			lo = mid + 1;
		} else {
			ans = mid;
			hi = mid-1;
		}
	}
	if(ans == n)
		ans = -1;
	return ans;
}

int queryL(int v , int tl , int tr , int x) {
	if(tree[v] < x) // No value >= x
		return -1;
	if(tl == tr)
		return tl;
	int tmid = (tl + tr)/2;
	if(tree[2*v] >= x) 
		return queryL(2*v , tl , tmid , x);
	else 
		return queryL(2*v + 1, tmid + 1 , tr , x);
}


int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n; ++i )
		cin >> a[i];
	build(1 , 0 , n-1);
	while(m--) {
		int q;
		cin >> q;
		if(q == 1) {
			int i , v;
			cin >> i >> v;
			update(1 , 0 , n-1 , i , v);
		} else {
			int x;
			cin >> x;
			cout << bs(x) << "\n";
			// cout << queryL(1 , 0 , n-1 , x) << "\n";
		}
	}
}