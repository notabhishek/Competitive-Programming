// Sum over Subset DP
// Given masks
// Q queries, in each query we have a mask
// find the count of masks that are supermask of this
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> f;
vector<vector<int>> dp;

int sos(int t, int i) {
	// cout << "call "<< t << " " << i << endl;
	if(dp[t][i] != -1)
		return dp[t][i];
	if(i == 0) 
		return dp[t][0] = f[t];

	if(t & (1<<(i-1))) 
		dp[t][i] = sos(t, i-1);
	else 
		dp[t][i] = sos(t, i-1) + sos(t ^ (1<<(i-1)), i-1);
	return dp[t][i];
}
void solve()
{
	int m;
	cin >> m;
	vector<int> a(m);
	n = 0;
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
		n = max(n ,(int)1 + (int)ceil(log2(a[i])));
	}
	f = vector<int>(1 << n , 0);
	for(auto &i : a) f[i] = 1;
	
	dp.resize(1<<n , vector<int>(n+1, -1));
	
	int q;
	cin >> q;
	while(q--) {
		int mask;
		cin >> mask;
		cout << sos(mask, n) << "\n";
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
