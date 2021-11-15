class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n  = nums.size();
        int ans = 0, idx = -1;
        vector<int> p(n, -1);
        vector<int> r(n, 1);
        for(int i = n-1; i >= 0; --i) {
            for(int j = i+1; j < n; ++j) {
                if(nums[j]%nums[i] == 0 && r[j]+1>r[i]) { 
                    r[i] = 1 + r[j];
                    p[i] = j;
                }
            }
            if(r[i] > ans) {
                ans = r[i];
                idx = i;
            }
        }
        vector<int> res;
        while(idx != -1) {
            res.push_back(nums[idx]);
            idx = p[idx];
        }
        return res;
    }
};
