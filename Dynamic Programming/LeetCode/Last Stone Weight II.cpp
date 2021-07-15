class Solution {
public:
    // let the optimal way to solve some stones be ((s1-s2)-s3)-(s4-s5)
    // some have positive sign some negative
    // same as find 2 subsets with minimal difference
    
    int lastStoneWeightII(vector<int>& a) {
        int sum = accumulate(a.begin() , a.end(), 0);
        int hsum = sum/2;
        vector<bool> dp(hsum + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < a.size(); ++i) {
            for(int j = hsum; j >= 0; --j) {
                if(a[i] <= j)
                    dp[j] = dp[j] ||  dp[j - a[i]];
            }
        }
        int mnD = INT_MAX;
        for(int i = 0; i <= hsum; ++i) {
            if(dp[i])
            mnD = min(mnD , sum-2*i);
        }
        return mnD;
    }
};
