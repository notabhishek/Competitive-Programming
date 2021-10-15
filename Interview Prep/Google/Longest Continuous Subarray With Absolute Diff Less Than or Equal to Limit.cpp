// Problem: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Solution 1: using multiset O(NlogN)
// Solution 2: using MaxDeque and MinDeque O(N)

// Solution 1: using multiset O(NlogN)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int i = 0, j = 0, n = nums.size();
        int ans = 0;
        while(i < n) {
            int diff = 0;
            while(j < n && diff <= limit) {
                window.insert(nums[j]);
                diff = (*window.rbegin()) - (*window.begin());
                ++j;
            }
            if(diff > limit) {
                --j;
                window.erase(window.find(nums[j]));
                diff = (*window.rbegin()) - (*window.begin());
            }
            if(diff <= limit) ans = max(ans, j - i);
            window.erase(window.find(nums[i]));
            ++i;
        }
        return ans;
    }
};

// Solution 2: using MaxDeque and MinDeque O(N)
