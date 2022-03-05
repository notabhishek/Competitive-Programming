class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for(int i : nums) m[i]++;
        int dp0 = 0, dp1 = 0, prev = -1000;
        for(auto &i : m) {
            int newDp0 = max(dp0, dp1);
            int newDp1 = i.first * i.second + (prev == i.first-1 ? dp0 : newDp0);
            dp0 = newDp0;
            dp1 = newDp1;
            prev = i.first;
        }
        return max(dp0, dp1);
    }
};
