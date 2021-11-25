class Solution {
public:

bool cmp(int i, int j, int l, string &s, vector<vector<int>> &same) {
	return same[i][j] >= l || s[i+same[i][j]] > s[j+same[i][j]];
}
int numberOfCombinations(string s) {
	int n = s.length();
	int dp[n][n+1], pre[n][n+1];
	memset(dp, 0, sizeof dp);
	memset(pre, 0, sizeof pre);
	vector<vector<int>> same(n+1, vector<int> (n+1, 0));
	for(int i = n-1; i >= 0; --i)
		for(int j = n-1; j >= 0; --j)	
			same[i][j] = (s[i] != s[j] ? 0 : 1 + same[i+1][j+1]);
			
	const int MOD = 1e9 + 7;
	
	for(int i = 0; i < n; ++i) {
		for(int l = 1; l <= i; ++l) {
			int idx1 = i-l+1, idx2 = i+1-l-l;
			if(s[i+1-l]=='0') {
				pre[i][l] = pre[i][l-1];
				continue;
			}
			dp[i][l] = (dp[i][l] + pre[i-l][l-1]) %MOD;
			if(i+1-2*l>=0 && cmp(i-l+1, i-l+1-l, l, s, same))
				dp[i][l] = (dp[i][l] + dp[i-l][l]) % MOD;
			pre[i][l] = (pre[i][l-1] + dp[i][l]) % MOD;
		}
		dp[i][i+1] = s[0] != '0';
		pre[i][i+1] = (pre[i][i] + dp[i][i+1]) % MOD;
		for(int l=i+2; l<=n; ++l) pre[i][l] = pre[i][i+1];
	}
	int ans = pre[n-1][n];
	return ans;
}
};
