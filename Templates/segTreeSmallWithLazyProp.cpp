// small segment tree with lazy propogation
#include<bits/stdc++.h>
using namespace std;

class segTree {
private:
	vector<int> t;
	vector<bool> clazy;
	vector<int> lazy;
	int n;
	int N;
public: 
	void merge(int &v, int &l, int &r) {
		v = l + r;
	}
	void prop(int v, int tl, int tr) {
		if(clazy[v]) {
			clazy[2*v] = clazy[2*v+1] = true;
			clazy[v] = false;
			
			lazy[2*v] += lazy[v];
			lazy[2*v+1] += lazy[v];
			
			t[v]+= lazy[v] * (tr-tl+1);
			lazy[v] = 0;
		}
	}
	void build(int v, int tl, int tr, vector<int> &a) {
		if(tl == tr) {
			t[v] = a[tl];
			return;
		}
		int tm = (tl+tr)/2;
		build(2*v, tl, tm, a);
		build(2*v+1, tm+1, tr, a);
		merge(t[v], t[2*v], t[2*v+1]);
	}
	segTree(vector<int> &a) {
		n = a.size();
		N = 2 * (1 << (int)(ceil(log2(n))+1));
		t.resize(N);
		clazy.assign(N, false);
		lazy.assign(N, 0);
		build(1, 0, n-1, a);
	}
	
	int query(int v, int tl, int tr, int l, int r) {
		if(clazy[v]) prop(v, tl, tr);
		if(tl > r || tr < l) return 0;
		if(tl >= l && tr <= r) return t[v];
		int tm = (tl+tr)/2;
		int L = query(2*v, tl, tm, l, r);
		int R = query(2*v+1, tm+1, tr, l, r);
		int ans;
		merge(ans, L, R);
		return ans;
	}
	
	void update(int v, int tl, int tr, int l, int r, int val) {
		if(clazy[v]) prop(v, tl, tr);
		if(tl > r || tr < l) return;
		if(tl>=l && tr <= r) {
			clazy[v] = true;
			lazy[v] += val;
			prop(v, tl, tr);
			return;
		} 
		int tm = (tl + tr)/2;
		update(2*v, tl, tm, l, r, val);
		update(2*v+1, tm+1, tr, l, r, val);
		merge(t[v], t[2*v], t[2*v+1]);
	}
	
	
	int query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
	
	int query(int l) {
		return query(1, 0, n-1, l, l);
	}
	
	void update(int l, int r, int v) {
		update(1, 0, n-1, l, r, v);
	}
	
	void update(int l, int v) {
		update(1, 0, n-1, l, l, v);
	}
};

int main() {
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a) cin >> i;
	
	segTree tree(a);
	
	cout << "point queries\n";
	cout << tree.query(0) << "\n";
		
	cout << "range queries\n";
	cout << tree.query(1, 5) << "\n";
	
	cout << "point updates\n";
	tree.update(2, 4);
	
	cout << "range updates\n";
	tree.update(1, 4, -2);
	
	return 0;
}
