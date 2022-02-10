class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen = {{0, 1}};
        int count = 0, sum = 0;
        for (auto n: nums) {
            sum += n;
            count += seen[sum - k];
            seen[sum]++;
        }
        return count;
    }
};
