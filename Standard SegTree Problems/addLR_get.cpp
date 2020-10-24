// add v to [l , r] and get(i)

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

const int MAXN = 1e5 + 1;
ll tree[4*MAXN];
ll a[MAXN];
ll n , m;

void build(int v , int tl, int tr){
	if(tl == tr)
		tree[v] = a[tl];
	else {
		int tmid = (tl + tr)/2;
		build(2*v , tl , tmid);
		build(2*v + 1 , tmid + 1 , tr);
		// tree[v] = tree[2*v] + tree[2*v + 1];
	}
}

void add(int v , int tl, int tr , int l , int r, int val) {
	if(tl > r || l > tr)
		return;
	if(tl >= l && tr<=r)
		tree[v] += val;
	else {
		int tmid = (tl + tr)/2;
		add(2*v , tl , tmid , l , r, val);
		add(2*v + 1, tmid + 1 ,tr ,  l , r , val);
	}
}

ll get(int v , int tl, int tr, int idx) {
	if(tl == tr)
		return tree[v];
	int tmid = (tl + tr)/2;
	if(idx > tmid) 
		return tree[v] + get(2*v + 1 , tmid + 1 , tr , idx);
	else
		return tree[v] + get(2*v , tl , tmid ,idx);
}
int main() {
	cin >> n >> m;
	// for(int i = 0 ; i < n; ++i) {
		// cin >> a[i];
	// }
	// build(1 , 0 , n-1);
	while(m--) {
		int q;
		cin >> q;
		if(q == 1) {
			int l , r, v;
			cin >> l >> r >> v;
			--r;
			add(1 , 0 , n-1 , l , r , v);
		} else {
			int i;
			cin >> i;
			cout << get(1 , 0 , n-1 , i) << endl;
		}
	}
}