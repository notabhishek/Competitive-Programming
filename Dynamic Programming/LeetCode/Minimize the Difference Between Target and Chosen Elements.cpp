class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        const int NAX= 70 * 70 + 1;
        bitset<NAX> sum;
        bitset<NAX> newsum;
        sum[0] = 1;
        
        for(auto &i : mat) {
            newsum = 0;
            for(auto &j : i) {
                newsum |= sum << j;
            }
            sum = newsum;
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < NAX; ++i) 
            if(sum[i]) ans = min(ans, abs(i - target));
        return ans;
    }
};
