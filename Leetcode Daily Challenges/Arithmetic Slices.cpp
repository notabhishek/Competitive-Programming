class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), i = 1;
        int ans = 0;
        
        while(i < n) {
            int j = i+1, d = nums[i] - nums[i-1];
            while(j < n && d == nums[j]-nums[j-1]) ++j;
            // (j-i-1) + (j-i-2) + ... + 1
            ans += (j-i-1) * (j-i) / 2;
            i = j;
        }
        
        return ans;
    }
};
