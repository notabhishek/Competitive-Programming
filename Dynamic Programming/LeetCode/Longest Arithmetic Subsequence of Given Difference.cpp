class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        unordered_map<int, int> dp;
        int ans = 1;
        for(auto &i : a) {
            if(dp.count(i-d)) { 
                dp[i] = max(dp[i], 1 + dp[i-d]);
                ans = max(ans, dp[i]);
            }
            else 
                dp[i] = 1;
        }
        return ans;
    }
};
