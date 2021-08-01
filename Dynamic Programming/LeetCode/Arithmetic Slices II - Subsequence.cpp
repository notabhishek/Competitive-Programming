using ll = long long;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        map< ll, int> dp[n];
        // dp[i][ d ] = number of subseq ending at i, having difference d
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j< i; ++j) {
                ll d = (ll)a[i] - (ll)a[j];
                int cur = (dp[j].count(d) ? 1 + dp[j][d] : 1);
                dp[i][d] += cur;
                ans += cur;
            }
        }
        // subtract 2 length
        ans -= ((n-1)*(n))/2;
        return ans;
        
    }
};
