#include <bits/stdc++.h>
using namespace std;

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  int max_log;
  vector<vector<T>> st;
  F func;
 
  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    max_log = 32 - __builtin_clz(n);
    st.resize(max_log);
    st[0] = a;
    for (int j = 1; j < max_log; j++) {
      st[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        st[j][i] = func(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
   
  // for idempotent F O(1)
  T get(int L, int R) const {
    assert(0 <= L && L <= R && R <= n - 1);
    int lg = 32 - __builtin_clz(R - L + 1) - 1;
    return func(st[lg][L], st[lg][R - (1 << lg) + 1]);
  }
  // for non idempotent F O(lg n)
  T get2(int L, int R) const {
    assert(0 <= L && L <= R && R <= n - 1);
    T ans = 0; // change this 
    int lg = 32 - __builtin_clz(R - L + 1) - 1;
	for (int j = lg; j >= 0; j--) {
	    if ((1 << j) <= R - L + 1) {
	        ans = func(ans, st[j][L]);
	        L += 1 << j;
	    }
	}
    return ans;
  }
  // if st is decreasing e.g. gcd, min
  // Return first index R where [L...R] < val
  T upper(int L, int val) {
  	int lg = 32 - __builtin_clz(n-L) - 1;
  	T ans = 0, cur;
  	for(int j = lg; j>=0; --j) {
  		if( (1<<j) <= n-L ) {
  			assert(st.size()>j && st[j].size() > L);
	  		cur = func(ans, st[j][L]);
	  		if(cur >= val) {
	  			ans = cur;
	  			L += 1 << j;
	  		}
  		}
  	}
  	return L;
  }
  
  // if st is increasing e.g. max, sum
  // Return first index R where [L...R] > val
  T lower(int L, int val) {
  	int lg = 32 - __builtin_clz(n-L) - 1;
  	T ans = 0, cur;
  	for(int j = lg; j>=0; --j) {
  		if( (1<<j) <= n-L ) {
  			assert(st.size()>j && st[j].size() > L);
	  		cur = func(ans, st[j][L]);
	  		if(cur <= val) {
	  			ans = cur;
	  			L += 1 << j;
	  		}
  		}
  	}
  	return L;
  }
  
};

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	
	// SparseTable<int> st(a, [&](int i, int j) {
		// return i + j; // // change get2 default to 0
	// });
	
	// SparseTable<int> st(a, [&](int i, int j){ 
		// return i*j; // change get2 default to 1
	// });
	
	// SparseTable<int> st(a, [&](int i, int j){
		// if(i == 0 || j == 0) return i+j; 
		// return __gcd(i, j);
	// });
	
	SparseTable<int> st(a, [&](int i, int j){
		return min(i, j); // change get2 default to INF
	});
	
	int q;
	cin >> q;
	while(q--) {
		int l , r; // 0 based indexing
		cin >> l >> r;
		cout << st.get2(l, r) << endl;
	}
}

signed main()
{
	solve();
}
