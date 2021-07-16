class Solution {
public:
    int closestCost(vector<int>& b, vector<int>& t, int k) {
        int n = b.size();
        int m = t.size();
        int NAX = accumulate(t.begin() , t.end(), 0) * 2  + *max_element(b.begin(), b.end()) + 5;
        vector<bool> dp(NAX, 0);
        dp[0] = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = NAX-1; j > 0; --j) {
                if(t[i] <= j)
                    dp[j] = dp[j] || dp[j-t[i]];
                if(2*t[i] <= j)
                    dp[j] = dp[j] || dp[j-2*t[i]];
            }
        }
        
        
        int ans = INT_MAX, dmn = INT_MAX;
        for(auto &i : b) {
            for(int j = NAX-1; j >= 0; --j) {
                if(j>=i && dp[j - i] && abs(j - k) <= dmn) {
                    if(abs(j-k) < dmn) {
                        ans = j;
                        dmn = abs(j-k);
                    } else {
                        ans = min(ans, j);
                    }
                }
            }
        }
        return ans;
    }
};
