#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 1;
int n;
int t[ 4*MAXN ];

void build(vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
	
	int m;
	cin >> n >> m;
	++n;
	vector<int> a(n , 0);
	for(int i = 1 ; i < n; ++i) {
		cin >> a[i];
	}
	build(a , 1 , 0 , n-1);
	while( m-- ) {
		int q , l , r;
		cin >> q >> l >> r;
		if( q == 1) {
			update(1 , 0 , n-1, l , r);
		} else {
			cout << sum(1 , 0 , n-1 , l , r) << "\n";
		}
	}
}