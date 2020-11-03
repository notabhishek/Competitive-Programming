class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double dp[n];
        double pref[n];
        dp[n-1] = 1;
        pref[n-1] = 1;
        for(int i = n-2;i >= 0; --i) {
            dp[i] = pref[i+1];
            dp[i]/= (double)(n-i);
            pref[i] = pref[i + 1] + dp[i];
        }
        return dp[0];
    }
};