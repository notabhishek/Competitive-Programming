// Sum over Subset DP
// Given masks
// Q queries, in each query we have a mask
// find the number of masks that are subset of this
#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int m;
	cin >> m;
	vector<int> a(m);
	int n = 0;
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
		n = max(n ,(int)1 + (int)ceil(log2(a[i])));
	}
	vector<int> f(1 << n , 0);
	for(auto &i : a) f[i] = 1;
	
	int dp[1<<n][n+1];
	for(int t = 0; t < (1<<n); ++t) {
		dp[t][0] = f[t];
		for(int i = 1; i <= n; ++i) {
			if(t & (1<<(i-1))) 
				dp[t][i] = dp[t][i-1] + dp[t ^ (1<<(i-1))][i-1];
			else 
				dp[t][i] = dp[t][i-1];
		}
	}
	
	int q;
	cin >> q;
	while(q--) {
		int mask;
		cin >> mask;
		cout <<dp[mask][n] << "\n";
	}
}

signed main()
{
	solve();
}
/*
Input: 
5
1 2 3 4 5
4
6
5
4
7

Output:
2
3
1
5
*/
