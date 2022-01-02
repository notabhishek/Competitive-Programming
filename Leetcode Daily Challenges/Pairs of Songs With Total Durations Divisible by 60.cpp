class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> f(60, 0);
        int ans = 0;
        for(int t : time) {
            t%=60;
            ans += f[(60-t)%60];
            f[t]++;
        }
        return ans;
    }
};
