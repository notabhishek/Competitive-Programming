class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int csum = 0;
        for(int i : nums) {
            csum += i;
            ans = max(ans, csum);
            csum = max(csum, 0);
        }
        return ans;
    }
};
