class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return idx == nums.size() || nums[idx] != target ? -1 : idx;
    }
};
