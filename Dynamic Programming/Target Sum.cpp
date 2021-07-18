class Solution {
public:
    int findTargetSumWays(vector<int>& a, int k) {
        int sum = accumulate(a.begin() , a.end() , 0);
        int n = a.size() , ans = 0;
        int MSUM = 1000 * n + 1;
        map< int , int> dp;
        
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = MSUM-1; j >= 0; --j) {
                if(dp.count(j - a[i])) 
                    dp[j] += dp[j-a[i]];
            }
        }
        for(auto &i : dp) {
            if((i.first - (sum - i.first)) == k)
                ans += i.second;
        }
        return ans;
    }
};
