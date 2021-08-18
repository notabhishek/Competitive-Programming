// find max sum subarray in [l , r]

#include<bits/stdc++.h>
#define int int64_t
using namespace std;

struct data {
	int seg;
	int pref;
	int suff;
	int sum;
	void print() {
		cout << "SEG : " << seg << " P : "<< pref << " S: "<< suff << " sum: "<< sum << endl;
	}
};

struct data combine(struct data a ,struct data b){
	struct data c;
	c.sum = a.sum + b.sum;
	c.seg = max( max(a.seg , b.seg) , max(a.suff + b.pref , max(a.sum + b.pref , a.suff + b.sum) ) );
	c.pref = max(a.pref , a.sum + b.pref);
	c.suff = max(b.suff , a.suff + b.sum);
	return c;
}

const int MAXN = 1e5 + 1;
struct data tree[ 4 * MAXN];
int a[MAXN];
int n , m;



void build(int v , int tl , int tr){
	if(tl == tr) {
		int val = max((int)0, a[tl]);
		tree[v].seg = tree[v].pref = tree[v].suff = val;
		tree[v].sum = a[tl];
	} else {
		int tmid = (tl + tr)/2;
		build(2*v , tl , tmid);
		build(2*v + 1 , tmid + 1 , tr);
		tree[v] = combine(tree[2*v] , tree[2*v+1]);
		
	}
}

void update(int v , int tl , int tr, int idx, int val) {
	if(tl == tr) {
		int val2 = max((int)0, val);
		tree[v] = { val2 , val2 , val2 , val};
	} else {
		int tmid = (tl + tr)/2;
		if(idx > tmid) 
			update(2*v + 1 , tmid + 1 , tr , idx , val);
		else 
			update(2*v , tl , tmid , idx , val);
		tree[v] = combine(tree[2*v] , tree[2*v + 1]);
	}
}

struct data query(int v , int tl , int tr, int l , int r) {
	if(l > tr || tl > r)  
		return  {0 , 0 , 0 , 0};
	if(tl>=l && tr<=r) 
		return tree[v];
	int tmid = (tl + tr)/2;
	return combine(query(2*v , tl , tmid , l , r) , query(2*v + 1 , tmid + 1, tr , l , r));
}
int32_t main() {
	cin >> n >> m;
	for(int i = 0 ; i < n; ++i) 
		cin >> a[i];
	build(1 , 0 , n-1);
	cout << query(1 , 0 , n-1 , 0 , n-1).seg << "\n";
	while( m-- ){
		int l , r;
		cin >> l >> r;
		update(1 , 0 , n-1 , l , r);
		cout << query(1 , 0 , n-1 , 0 , n-1).seg << "\n";
	}
	
}
