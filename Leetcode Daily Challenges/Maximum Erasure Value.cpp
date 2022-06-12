class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, ans = 0, i = 0, j = 0, n = nums.size();
        unordered_set<int> seen;
        while(j < n) {
            if(seen.count(nums[j])) {
                ans = max(ans, sum);
                sum -= nums[i];                
                j = max(j, i);
                seen.erase(nums[i++]);
            } else {
                sum += nums[j];
                seen.insert(nums[j++]);
            }
        }
        ans = max(ans, sum);
        return ans;
    }
};
