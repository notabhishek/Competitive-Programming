// Problem: Digit Sum
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/PR003004/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms

// Code by : Abhishek Tiwari @devil_within
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

#define int int64_t

int ans = 0;
const int MX_LEN = 17;
vector<vector<pair<int,int>>> dp; // {count, sum}
pair<int,int> recur(string &R, int n, bool rt) {
	if(n == 0) return {1, 0};
	pair<int,int> &ret = dp[n][rt];
	if(ret.first != -1) return ret;
	
	int ub = rt ? R[R.length()-n]-'0': 9;
	ret = {0, 0}; 
	for(int dig = 0; dig <= ub; ++dig) {
		auto p = recur(R, n-1, rt&(dig==ub));
		ret.first += p.first;
		ret.second += p.second + p.first * dig;
	}
	return ret;
}

void solve()
{
	int L, R;
	cin >> L >> R;
	ans = 0;
	string sl = to_string(L-1), sr = to_string(R);
	dp.assign(sr.length()+1, vector<pair<int,int>>(2, mp(int(-1), int(-1))));
	auto ans1 = recur(sr, sr.length(), 1);
	
	dp.assign(sr.length()+1, vector<pair<int,int>>(2, mp(int(-1), int(-1))));
	auto ans2 = L == 0 ? mp((int)0,(int)0) : recur(sl, sl.length(), 1);
	// cout << ans1 <<  " " << ans2 << "\n";
	cout << ans1.second - ans2.second << "\n";
}
signed main()
{
    // freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" ,stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        // cout << "Case #"<<tc<<": \n";
        solve();
    }
}
