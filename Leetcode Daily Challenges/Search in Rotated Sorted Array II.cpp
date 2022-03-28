class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(nums.begin(), nums.end(), target) != nums.end();
    }
};
