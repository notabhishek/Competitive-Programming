class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int N = 1 << (2*n);
        vector<vector<int>> s2(n+1); // s[set bits] = {subset sums}
        vector<vector<int>> s1(n+1);
        sort(nums.begin(), nums.end());
        int SUM1 = accumulate(nums.begin(), nums.begin()+n,0), SUM2 = accumulate(nums.begin()+n, nums.end(), 0);
        for(int m = (1<<n)-1; m >= 0; --m) {
            int sum1 = 0, sum2 = 0;
            for(int i = 0; i < n; ++i) {
                if(m & (1<<i)) {
                    sum1 += nums[i];
                    sum2 += nums[i+n];
                }
            }
            int b = __builtin_popcount(m);
            s1[b].push_back(2*sum1-SUM1);
            s2[b].push_back(2*sum2-SUM2);
        }
        int SUM = accumulate(nums.begin(), nums.end(), 0);
        int ans = 1e9;
        for(int b1 = 0; b1 <= n; ++b1) {
            int b2 = n-b1;
            sort(s2[b2].begin(), s2[b2].end());
            for(int i : s1[b1]) {
                auto it = lower_bound(s2[b2].begin(), s2[b2].end(), -i);
                if(it != s2[b2].end()) {
                    ans = min(ans, abs(i + *it));
                }
                if(it != s2[b2].begin()) {
                    --it;
                    ans = min(ans, abs(i + *it));
                }
            }
        }
        return ans;
    }
};
